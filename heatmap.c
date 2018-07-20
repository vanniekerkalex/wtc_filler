/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:51:10 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/20 13:24:24 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

/* Duplicates maps into heatmap */
int		**fill_heatmap(struct maps maps, int **heatmap, int y, int x);
void print_heatmap(struct maps maps, int **heatmap);
int	check_boundary(struct maps maps, int tx, int ty);

int	**init_heatmap(struct maps maps)
{
	int i;
	int j;
	int **heatmap;

	i = 0;
	heatmap = (int **)malloc(sizeof(int *) * (maps.dim_y));
	while (i < maps.dim_y)
	{
		heatmap[i] = (int *)malloc(sizeof(int) * (maps.dim_x));
		j = 0;
		while (j < maps.dim_x)
		{
			heatmap[i][j] = 0;
			if (maps.map[i][j] == 'X' || maps.map[i][j] == 'x')
				heatmap[i][j] = -1;
			if (maps.map[i][j] == 'O' || maps.map[i][j] == 'o')
				heatmap[i][j] = -2;
			j++;
		}
		i++;
	}
	return (heatmap);
}

int		**find_enemy_token(struct maps maps, int **heatmap)
{
	int piece;
	int i;
	int j;

	i = 0;
	(maps.c_piece == 'x') ? (piece = -2) : (piece = -1);
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			if (heatmap[i][j] == piece)
			{
				//write(1, "b4", 2);
				heatmap = fill_heatmap(maps, heatmap, i, j);
				//write(1, "af", 2);
			}
			j++;
		}
		i++;
	}
	return (heatmap);
}

int		**fill_heatmap(struct maps maps, int **heatmap, int y, int x)
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
			(check_boundary(maps, tx, ty) && heatmap[ty][tx] >= 0 && heatmap[ty][tx] <= max - i) && (heatmap[ty][tx] = max - i);
			ty--;
		}
		ty++;
		while (tx >= x - i) // Loop 2 - left
		{
			(check_boundary(maps, tx, ty) && heatmap[ty][tx] >= 0 && heatmap[ty][tx] <= max - i) && (heatmap[ty][tx] = max - i);
			tx--;
		}
		tx++;
		while (ty <= y + i) // Loop 3 - down
		{
			(check_boundary(maps, tx, ty) && heatmap[ty][tx] >= 0 && heatmap[ty][tx] <= max - i) && (heatmap[ty][tx] = max - i);
			ty++;
		}
		ty--;
		while (tx <= x + i) // Loop 4 - right
		{
			(check_boundary(maps, tx, ty) && heatmap[ty][tx] >= 0 && heatmap[ty][tx] <= max - i) && (heatmap[ty][tx] = max - i);
			tx++;
		}
		tx--;
		i++;
	}
	return (heatmap);
}

int	check_boundary(struct maps maps, int tx, int ty)
{
	if (tx < maps.dim_x && tx >= 0 && ty < maps.dim_y && ty >= 0)
		return(1);
	else
		return (0);
}

void print_heatmap(struct maps maps, int **heatmap)
{
	int i;
	int j;

	i = 0;
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			printf("%d ", heatmap[i][j++]);
		}
		printf("\n");
		i++;
	}
}
