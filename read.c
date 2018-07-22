/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:56:42 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/22 12:31:30 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_player(t_maps *maps);
void	ft_read_map(t_maps *maps, int flag);
void	ft_read_token(t_maps *maps, int flag);
void	set_players(t_maps *maps, int flag);
void	ft_read_dim(t_maps *maps, char *line, int flag);
char	**ft_pop_map(char **map, int rows, int flag);
t_maps	*init_struct();
t_token	*init_struct_token();

void	ft_read(t_maps *maps, int flag)
{
	if (flag == 0)
		ft_read_player(maps);
	ft_read_map(maps, flag);
	ft_read_token(maps, 2);
}

void ft_read_player(t_maps *maps)
{
	char	*line;

	get_next_line(0, &line); //Player
	if (ft_strncmp(ft_strchr(line, ':') - 2, "1", 1) == 0)
		set_players(maps, 1);
	else
		set_players(maps, 0);
}

void	ft_read_map(t_maps *maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Plateau
	if (flag == 0)
		ft_read_dim(maps, line, flag);
	get_next_line(0, &line); // numbers
	maps->map = (char**)malloc(sizeof(char*) * (maps->dim_y + 1));
	while (i < maps->dim_y)
	{
		maps->map[i] = (char*)malloc(sizeof(char) * (maps->dim_x + 1));
		i++;
	}
	maps->map = ft_pop_map(maps->map, maps->dim_y, flag);
}

void	ft_read_token(t_maps *maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Piece
	ft_read_dim(maps, line, flag);
	maps->t_map = (char**)malloc(sizeof(char*) * (maps->dim_ty + 1));
	while (i < maps->dim_ty)
	{
		maps->t_map[i] = (char*)malloc(sizeof(char) * (maps->dim_tx + 1));
		i++;
	}
	maps->t_map = ft_pop_map(maps->t_map, maps->dim_ty, flag);
}

void set_players(t_maps *maps, int flag)
{
	if (flag == 1)
	{
		maps->c_piece = 'o';
		maps->e_piece = 'x';
		maps->c_flag = -2;
		maps->e_flag = -1;
	}
	else
	{
		maps->c_piece = 'x';
		maps->e_piece = 'o';
		maps->c_flag = -1;
		maps->e_flag = -2;
	}
}

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
	size_t	j;
	size_t	bound;
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
