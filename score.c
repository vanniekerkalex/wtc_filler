/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:48:17 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/22 13:35:10 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

#include <fcntl.h>

int check_overlap(t_maps *maps, t_token *token);
int calc_score(t_maps *maps, t_token *token);

void	find_coords(t_maps *maps, t_token *token)
{
	int i;
	int j;
	int calc;

	maps->score = 0;
	maps->score_x = 0;
	maps->score_y = 0;
	
	i = 0;
	while (i < maps->dim_y - token->dim_y)
	{
		j = 0;
		while (j < maps->dim_x - token->dim_x)
		{
			maps->coords_y = i;
			maps->coords_x = j;
			//if(check_boundary(maps, j + maps->dim_tx - token->col_right - token->col_left, i + maps->dim_ty - token->row_bottom - token->row_top))
			if (check_overlap(maps, token))
			{
				if ((calc = calc_score(maps, token)) > maps->score)
				{
					maps->score = calc;
					maps->score_x = j - token->col_left;
					maps->score_y = i - token->row_top;
					write(2, "----------\n",11);
					ft_putnbr_fd(maps->score_y,2);
					ft_putchar_fd(' ',2);
					ft_putnbr_fd(maps->score_x,2);
					ft_putchar_fd(' ',2);
					ft_putnbr_fd(maps->score,2);
					ft_putchar_fd('\n',2);
				}
			}
			j++;
		}
		i++;
	}
}

int     check_overlap(t_maps *maps, t_token *token)
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
            if (maps->t_map[i + token->row_top][j + token->col_left] == '*' && maps->heatmap[maps->coords_y + i][maps->coords_x + j] == maps->c_flag)
                count++;
            if ((maps->t_map[i + token->row_top][j + token->col_left] == '*' && maps->heatmap[maps->coords_y + i][maps->coords_x + j] == maps->e_flag) || count > 1) //Fail on enemny overlap
                return (0);
            j++;
        }
        i++;
    }
    if (count == 0)
        return (0);
    return (1);
}

int calc_score(t_maps *maps, t_token *token)
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
