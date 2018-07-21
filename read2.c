/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:56:42 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/21 20:43:56 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct maps ft_read_player(struct maps maps);
struct maps ft_read_map(struct maps maps, int flag);
struct maps ft_read_token(struct maps maps, int flag);
struct maps set_players(struct maps maps, int flag);
struct maps ft_read_dim(struct maps maps, char *line, int flag);
char        **ft_pop_map(char **map, int rows, int flag);
struct maps		init_struct(struct maps maps);

struct maps	ft_read(struct maps maps, int flag)
{
	if (flag == 0)
		maps = ft_read_player(maps);
	maps = ft_read_map(maps, flag);
	maps = ft_read_token(maps, 2);
	return (maps);
}

struct maps ft_read_player(struct maps maps)
{
	char	*line;

	get_next_line(0, &line); //Player
	if (ft_strncmp(ft_strchr(line, ':') - 2, "1", 1) == 0)
		maps = set_players(maps, 1);
	else
		maps = set_players(maps, 0);
	return (maps);
}

struct maps	ft_read_map(struct maps maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Plateau
	if (flag == 0)
		maps = ft_read_dim(maps, line, flag);
	get_next_line(0, &line); // numbers
	maps.map = (char**)malloc(sizeof(char*) * (maps.dim_y + 1));
	while (i < maps.dim_y)
	{
		maps.map[i] = (char*)malloc(sizeof(char) * (maps.dim_x + 1));
		i++;
	}
	maps.map = ft_pop_map(maps.map, maps.dim_y, flag);
	return (maps);
}

struct maps	ft_read_token(struct maps maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Piece
	maps = ft_read_dim(maps, line, flag);
	maps.t_map = (char**)malloc(sizeof(char*) * (maps.dim_ty + 1));
	while (i < maps.dim_ty)
	{
		maps.t_map[i] = (char*)malloc(sizeof(char) * (maps.dim_tx + 1));
		i++;
	}
	maps.t_map = ft_pop_map(maps.t_map, maps.dim_ty, flag);
	return (maps);
}

struct maps set_players(struct maps maps, int flag)
{
	if (flag == 1)
	{
		maps.c_piece = 'o';
		maps.e_piece = 'x';
		maps.c_flag = -2;
		maps.e_flag = -1;
	}
	else
	{
		maps.c_piece = 'x';
		maps.e_piece = 'o';
		maps.c_flag = -1;
		maps.e_flag = -2;
	}
	return (maps);
}

struct maps	ft_read_dim(struct maps maps, char *line, int flag)
{
	char	**tmp;

	tmp = ft_strsplit(line, ' ');
	if (flag == 0)
	{
		maps.dim_y = ft_atoi(tmp[1]);
		maps.dim_x = ft_atoi(tmp[2]);
	}
	else
	{
		maps.dim_ty = ft_atoi(tmp[1]);
		maps.dim_tx = ft_atoi(tmp[2]);
	}
	return (maps);
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
		get_next_line(0, &line); //start of . and x and o
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

struct maps	init_struct(struct maps maps)
{
	maps.map = NULL;
	maps.t_map = NULL;
	maps.heatmap = NULL;
	maps.dim_x = 0;
	maps.dim_y = 0;
	maps.dim_tx = 0;
	maps.dim_ty = 0;
	maps.c_piece = '\0';
	maps.e_piece = '\0';
	maps.c_flag = 0;
	maps.e_flag = 0;
	return (maps);
}
