/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/18 15:48:17 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/18 17:14:44 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int check_overlap(struct maps maps, int **heatmap, struct token token, struct coords coords);
int calc_score(struct maps maps, int **heatmap, struct token token, struct coords coords);

struct  score find_coords(struct maps maps, int **heatmap, struct token token)
{
    struct score score;
    struct coords coords;
    int i;
    int j;
    int calc;

    i = 0;
    while (i < maps.dim_y - maps.dim_ty + token.row_top + token.row_bottom)
    {
        j = 0;
        while (j < maps.dim_x - maps.dim_tx + token.col_left + token.col_right)
        {
            coords.y = i;
            coords.x = j;
            if(check_boundary(maps, j + token.col_right, i + token.row_bottom))
                if (check_overlap(maps, heatmap, token, coords))
                    if ((calc = calc_score(maps, heatmap, token, coords)) > score.score)
                    {
                        score.score = calc;
                        score.x = j + token.col_left;
                        score.y = i + token.row_top;
                    }
            j++;
        }
        i++;
    }
    return (score);
}

int     check_overlap(struct maps maps, int **heatmap, struct token token, struct coords coords)
{
    int i;
    int j;
    int piece;
    int count;

    i = 0;
    count  = 0;
    (maps.c_piece == 'x') ? (piece = -2) : (piece = -1);
    while (i < maps.dim_ty - token.row_top - token.row_bottom)
    {
        j = 0;
        while (j < maps.dim_tx - token.col_left - token.col_right)
        {
            if ((maps.t_map[i][j] == '*') && (heatmap[coords.y + i][coords.x + j] == -1 ||
            heatmap[coords.y + i][coords.x + j] == -2))
                count++;
            if (count > 1)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int calc_score(struct maps maps, int **heatmap, struct token token, struct coords coords)
{
    int count;
    int i;
    int j;

    i = 0;
    count = 0;
    while (i < maps.dim_ty - token.row_top - token.row_bottom)
    {
        j = 0;
        while (j < maps.dim_tx - token.col_left - token.col_right)
        {
            if (maps.t_map[i][j] == '*')
                count += heatmap[coords.y + i][coords.x + j];
            j++;
        }
        i++;
    }
    return (count);
}
