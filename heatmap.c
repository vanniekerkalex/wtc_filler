/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:51:10 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/18 12:58:54 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

/* Duplicates maps into heatmap */
char	**init_heatmap(struct maps maps)
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
			if (maps.map[i][j] == 'X')
				heatmap[i][j] = -1;
			if (maps.map[i][j] == 'O')
				heatmap[i][j] = -2;
			j++;
		}
		i++;
	}
	return (heatmap);
}

int		**find_enemy_token(struct maps maps, int **heatmap, char c_piece)
{
	int piece;
	int i;
	int j;

	i = 0;
	(c_piece == 'x') ? (piece = -2) : (piece = -1);
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			if (heatmap[i][j] == piece)
			{
				heatmap = fill_heatmap(heatmap, i, j);
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
		while (ty-- >= y - i) // Loop 1 - up
			((ty + 1 < dim_y) && heatmap[ty + 1][tx] <= score) && (heatmap[ty + 1][tx] = max - i);
		while (tx-- >= x - i) // Loop 2 - left
			((tx + 1 < dim_x) && heatmap[ty][tx + 1] <= score) && (heatmap[ty][tx + 1] = max - i);
		while (ty++ <= y + i) // Loop 3 - down
			((ty - 1 >= 0) && heatmap[ty - 1][tx] <= score) && (heatmap[ty - 1][tx] = max - i);
		while (tx++ <= x + i) // Loop 4 - right
			((tx - 1 >= 0) && heatmap[ty][tx - 1] <= score) && (heatmap[ty][tx - 1] = max - i);
		i++;
	}
	return (heatmap);
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
