/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:51:10 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/21 14:25:38 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

/* Duplicates maps into heatmap */
struct maps fill_heatmap(struct maps maps, int y, int x);
void print_heatmap(struct maps maps);
int	check_boundary(struct maps maps, int tx, int ty);

struct maps init_heatmap(struct maps maps)
{
	int i;
	int j;

	i = 0;
	maps.heatmap = (int **)malloc(sizeof(int *) * (maps.dim_y));
	while (i < maps.dim_y)
	{
		maps.heatmap[i] = (int *)malloc(sizeof(int) * (maps.dim_x));
		j = 0;
		while (j < maps.dim_x)
		{
			maps.heatmap[i][j] = 0;
			if (maps.map[i][j] == 'X' || maps.map[i][j] == 'x')
				maps.heatmap[i][j] = -1;
			if (maps.map[i][j] == 'O' || maps.map[i][j] == 'o')
				maps.heatmap[i][j] = -2;
			j++;
		}
		i++;
	}
	return (maps);
}

struct maps find_enemy_token(struct maps maps)
{
	int i;
	int j;

	i = 0;
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			if (maps.heatmap[i][j] == maps.e_flag)
				maps = fill_heatmap(maps, i, j);
			j++;
		}
		i++;
	}
	return (maps);
}

struct maps fill_heatmap(struct maps maps, int y, int x)
{
	int max;
	int i;
	int tx;
	int ty;

	i = 1;
	(maps.dim_y > maps.dim_x) ? (max = maps.dim_y) : (max = maps.dim_x);
	while (i < max)
	{
		ty = y + i;
		tx = x + i;
		while (ty >= y - i) // Loop 1 - up
		{
			(check_boundary(maps, tx, ty) && maps.heatmap[ty][tx] >= 0 && maps.heatmap[ty][tx] <= max - i) && (maps.heatmap[ty][tx] = max - i);
			ty--;
		}
		ty++;
		while (tx >= x - i) // Loop 2 - left
		{
			(check_boundary(maps, tx, ty) && maps.heatmap[ty][tx] >= 0 && maps.heatmap[ty][tx] <= max - i) && (maps.heatmap[ty][tx] = max - i);
			tx--;
		}
		tx++;
		while (ty <= y + i) // Loop 3 - down
		{
			(check_boundary(maps, tx, ty) && maps.heatmap[ty][tx] >= 0 && maps.heatmap[ty][tx] <= max - i) && (maps.heatmap[ty][tx] = max - i); //
			ty++;
		}
		ty--;
		while (tx <= x + i) // Loop 4 - right
		{
			(check_boundary(maps, tx, ty) && maps.heatmap[ty][tx] >= 0 && maps.heatmap[ty][tx] <= max - i) && (maps.heatmap[ty][tx] = max - i);
			tx++;
		}
		tx--;
		i++;
	}
	return (maps);
}

int	check_boundary(struct maps maps, int tx, int ty)
{
	if (tx < maps.dim_x && tx >= 0 && ty < maps.dim_y && ty >= 0)
		return(1);
	else
		return (0);
}

void print_heatmap(struct maps maps)
{
	int i;
	int j;

	i = 0;
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			ft_putnbr(maps.heatmap[i][j++]);
			write(1, " ", 1);
		}
		write(1,"\n", 1);
		i++;
	}
}
