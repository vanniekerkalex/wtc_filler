/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 19:51:10 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/18 10:47:29 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* Duplicates maps into heatmap */
char	**init_heatmap(struct maps maps)
{
	int i;
	int j;
	char **heatmap;

	i = 0;
	heatmap = (char **)malloc(sizeof(char *) * (maps.dim_y + 1));
	while (i < maps.dim_y)
	{
		heatmap[i] = (char *)malloc(sizeof(char) * (maps.dim_x + 1));
		j = 0;
		while (j < maps.dim_x)
			heatmap[i][j] = maps.map[i][j++];
		heatmap[i++][maps.dim_x] = '\0';
	}
	heatmap[i] = NULL;
	return (heatmap);
}

void find_enemy_token(struct maps maps, char **heatmap, char c_piece)
{
	char piece_low;
	char piece_up;
	int i;
	int j;

	/*if (c_piece == 'x')
		piece_low = 'o';
	else
		piece_low = 'x'; */
	i = 0;
	(c_piece == 'x') ? (piece_low = 'o') : (piece_low = 'x');
	piece_up = ft_toupper(piece_low);
	while (i < maps.dim_y)
	{
		j = 0;
		while (j < maps.dim_x)
		{
			if (heatmap[i][j] == piece_low || heatmap[i][j] == piece_up)
			{

			}
			j++;
		}
		i++;
	}
}

void fill_heatmap(char **heatmap)
{

}
