/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:25:03 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/23 12:15:12 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_overlap(t_maps *maps, t_token *token);
int		calc_score(t_maps *maps, t_token *token);
void	zero_scores(t_maps *maps);

void	find_coords(t_maps *maps, t_token *token)
{
	int i;
	int j;
	int calc;

	zero_scores(maps);
	i = 0;
	while (i <= maps->dim_y - token->dim_y)
	{
		j = 0;
		while (j <= maps->dim_x - token->dim_x)
		{
			maps->coords_y = i;
			maps->coords_x = j;
			if (check_overlap(maps, token))
				if ((calc = calc_score(maps, token)) > maps->score)
				{
					maps->score = calc;
					maps->score_x = j - token->col_left;
					maps->score_y = i - token->row_top;
				}
			j++;
		}
		i++;
	}
}

int		check_overlap(t_maps *maps, t_token *token)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < token->dim_y)
	{
		j = 0;
		while (j < token->dim_x)
		{
			if (maps->t_map[i + token->row_top][j + token->col_left] == '*' &&
					maps->heatmap[maps->coords_y + i][maps->coords_x + j] == maps->c_flag)
				count++;
			if ((maps->t_map[i + token->row_top][j + token->col_left] == '*' &&
						maps->heatmap[maps->coords_y + i][maps->coords_x + j] == maps->e_flag) || count > 1)
				return (0);
			j++;
		}
		i++;
	}
	if (count == 0)
		return (0);
	return (1);
}

int		calc_score(t_maps *maps, t_token *token)
{
	int count;
	int i;
	int j;

	i = 0;
	count = 0;
	while (i < token->dim_y)
	{
		j = 0;
		while (j < token->dim_x)
		{
			if (maps->t_map[i + token->row_top][j + token->col_left] == '*')
				count += maps->heatmap[maps->coords_y + i][maps->coords_x + j];
			j++;
		}
		i++;
	}
	return (count);
}

void	zero_scores(t_maps *maps)
{
	maps->score = 0;
	maps->score_x = 0;
	maps->score_y = 0;
}
