/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 13:01:55 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/22 14:10:28 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_dim(t_maps *maps, char *line, int flag);
char	**ft_pop_map(char **map, int rows, int flag);
t_maps	*init_struct();
t_token	*init_struct_token();

void	ft_read_dim(t_maps *maps, char *line, int flag)
{
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (flag == 0)
	{
		maps->dim_y = ft_atoi(tmp[1]);
		maps->dim_x = ft_atoi(tmp[2]);
	}
	else
	{
		maps->dim_ty = ft_atoi(tmp[1]);
		maps->dim_tx = ft_atoi(tmp[2]);
	}
}

char		**ft_pop_map(char **map, int rows, int flag)
{
	int		i;
	int		j;
	int		bound;
	char	*line;

	i = 0;
	while (i < rows)
	{
		get_next_line(0, &line); //start of -> and x and o
		if (flag == 1 || flag == 0) //if map then jump 4 units to right
			line = line + 4;
		j = 0;
		bound = ft_strlen(line);
		while (j < bound)
		{
			map[i][j] = *(line + j);
			j++;
		}
		//ft_strdel(&line);
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
	return (map);
}

t_maps	*init_struct()
{
	t_maps *map;
  	map = (t_maps *)malloc(sizeof(t_maps));
	map->map = NULL;
	map->t_map = NULL;
	map->heatmap = NULL;
	map->dim_x = 0;
	map->dim_y = 0;
	map->dim_tx = 0;
	map->dim_ty = 0;
	map->c_piece = '\0';
	map->e_piece = '\0';
	map->c_flag = 0;
	map->e_flag = 0;
	map->score = 0;
	map->score_x = 0;
	map->score_y = 0;
	map->coords_x = 0;
	map->coords_y = 0;
	return (map);
}

t_token	*init_struct_token()
{
	t_token *t;
  	t = (t_token *)malloc(sizeof(t_token));
	t->row_top = 0;
	t->col_left = 0;
	t->row_bottom = 0;
	t->col_right = 0;
	t->dim_x = 0;
	t->dim_y = 0;
	return (t);
}
