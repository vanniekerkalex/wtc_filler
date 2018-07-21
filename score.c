/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:48:17 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/21 20:44:48 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int check_overlap(struct maps maps, struct token token, struct coords coords);
int calc_score(struct maps maps, struct token token, struct coords coords);

struct  score find_coords(struct maps maps, struct token token)
{
    struct score score;
    struct coords coords;
    int i;
    int j;
    int calc;

    score.score = 0;
    score.x = 0;
    score.y = 0;
    i = 0;
    while (i < maps.dim_y - token.dim_y)
    {
        j = 0;
        while (j < maps.dim_x - token.dim_x)
        {
            coords.y = i;
            coords.x = j;
            //if(check_boundary(maps, j + maps.dim_tx - token.col_right - token.col_left, i + maps.dim_ty - token.row_bottom - token.row_top))
                if (check_overlap(maps, token, coords))
                {
                    if ((calc = calc_score(maps, token, coords)) > score.score)
                    {
                        score.score = calc;
                        score.x = j - token.col_left;
                        score.y = i - token.row_top;
                    }
                }
            j++;
        }
        i++;
    }
    return (score);
}

int     check_overlap(struct maps maps, struct token token, struct coords coords)
{
    int i;
    int j;
    int count;

    i = 0;
    count = 0;
    while (i < token.dim_y)
    {
        j = 0;
        while (j < token.dim_x)
        {
            if (maps.t_map[i + token.row_top][j + token.col_left] == '*' && maps.heatmap[coords.y + i][coords.x + j] == maps.c_flag)
                count++;
            if ((maps.t_map[i + token.row_top][j + token.col_left] == '*' && maps.heatmap[coords.y + i][coords.x + j] == maps.e_flag) || count > 1) //Fail on enemny overlap
                return (0);
            j++;
        }
        i++;
    }
    if (count == 0)
        return (0);
    return (1);
}

int calc_score(struct maps maps, struct token token, struct coords coords)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;
    while (i < token.dim_y)
    {
        j = 0;
        while (j < token.dim_x)
        {
            if (maps.t_map[i + token.row_top][j + token.col_left] == '*')
                count += maps.heatmap[coords.y + i][coords.x + j];
            j++;
        }
        i++;
    }
    return (count);
}
