/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 13:55:05 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/23 13:55:08 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fill_heatmap(t_maps *maps, int y, int x);
int		check_boundary(t_maps *maps, int tx, int ty);
void	set_points(t_maps *maps, int tx, int ty, int i);

void	init_heatmap(t_maps *maps)
{
	int i;
	int j;

	i = 0;
	maps->heatmap = (int **)malloc(sizeof(int *) * (maps->dim_y));
	while (i < maps->dim_y)
	{
		maps->heatmap[i] = (int *)malloc(sizeof(int) * (maps->dim_x));
		j = 0;
		while (j < maps->dim_x)
		{
			maps->heatmap[i][j] = 0;
			if (maps->map[i][j] == 'X' || maps->map[i][j] == 'x')
				maps->heatmap[i][j] = -1;
			if (maps->map[i][j] == 'O' || maps->map[i][j] == 'o')
				maps->heatmap[i][j] = -2;
			j++;
		}
		i++;
	}
}

void	find_enemy_token(t_maps *maps)
{
	int i;
	int j;

	i = 0;
	while (i < maps->dim_y)
	{
		j = 0;
		while (j < maps->dim_x)
		{
			if (maps->heatmap[i][j] == maps->e_flag)
				fill_heatmap(maps, i, j);
			j++;
		}
		i++;
	}
}

void	fill_heatmap(t_maps *maps, int y, int x)
{
	int max;
	int i;
	int tx;
	int ty;

	i = 1;
	(maps->dim_y > maps->dim_x) && (max = maps->dim_y);
	(maps->dim_y < maps->dim_x) && (max = maps->dim_x);
	while (i < max)
	{
		ty = y + i + 1;
		tx = x + i;
		while (--ty >= y - i)
			set_points(maps, tx, ty, i);
		ty += 2;
		while (--tx >= x - i)
			set_points(maps, tx, ty, i);
		while (++ty <= y + i)
			set_points(maps, tx, ty, i);
		ty -= 2;
		while (++tx <= x + i)
			set_points(maps, tx, ty, i);
		tx--;
		i++;
	}
}

int		check_boundary(t_maps *maps, int tx, int ty)
{
	if (tx < maps->dim_x && tx >= 0 && ty < maps->dim_y && ty >= 0)
		return (1);
	else
		return (0);
}

void	set_points(t_maps *maps, int tx, int ty, int i)
{
	int max;

	(maps->dim_y > maps->dim_x) && (max = maps->dim_y);
	(maps->dim_y < maps->dim_x) && (max = maps->dim_x);
	(check_boundary(maps, tx, ty) && maps->heatmap[ty][tx] >= 0 &&
	maps->heatmap[ty][tx] <= max - i) && (maps->heatmap[ty][tx] = max - i);
}
