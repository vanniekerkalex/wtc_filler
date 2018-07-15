/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:20:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/15 15:30:42 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

/*
**
**
**
*/

void	pop_map(char **line, char **map, int rows, int flag);

struct maps	ft_read_dim(struct maps maps, char **line, int flag)
{
	char	**tmp;

	tmp = ft_strsplit(*line, ' ');
	if (flag == 0)
	{
		maps.dim_x = ft_atoi(tmp[1]);
		maps.dim_y = ft_atoi(tmp[2]);
	}
	else
	{
		maps.dim_tx = ft_atoi(tmp[1]);
		maps.dim_ty = ft_atoi(tmp[2]);
	}
	return (maps);
}

void ft_player(char ** line, char c_piece)
{
	int ret;

	ret = get_next_line(0, line);
	while (ft_strncmp("$$$ exec p", *line, 10) != 0)
		ret = get_next_line(0, line);
	if (ft_strncmp(ft_strchr(*line, ':') - 2, "1", 1) == 0)
		c_piece = 'o';
	else
		c_piece = 'x';
	write(1, "hi", 2);
	write(1, &c_piece, 1);
}

struct maps		ft_init_map(int nrRows, char **map, char **t_map)
{
	int		ret;
	char	**line;
	char	c_piece;
	struct maps maps;

	line = NULL;
	c_piece = '\0';
	line = (char**)malloc(sizeof(*line) * 1);
	ft_player(line, c_piece);

	ret = get_next_line(0, line); //Plateau
	maps.map = NULL;
	maps.t_map = NULL;
	maps = ft_read_dim(maps, line, 0);
	maps.map = ft_read_map(maps, 0, map);
	maps = ft_read_token(maps, nrRows, t_map);
	return (maps);
}

char	**ft_read_map(struct maps maps, int flag, char **map)
{
	int		ret;
	int		i;
	char	**line;

	i = 0;
	line = (char**)malloc(sizeof(*line) * maps.dim_x);
	ret = get_next_line(0, line); //bunch of nums at beginning
	if (flag == 1) //After initail read map
		ret = get_next_line(0, line); //skips nums
    map = (char**)malloc(sizeof(char*) * (maps.dim_x + 1));
    while (i < maps.dim_x)
    {
        map[i] = (char*)malloc(sizeof(char) * (maps.dim_y + 1));
        i++;
	}
	pop_map(line, map, maps.dim_x, 1);
	return (map);
}

struct maps		ft_read_token(struct maps maps, int t_nrRows, char **t_map)
{
	int		ret;
	int		i;
	char	**line;

	line = (char**)malloc(sizeof(char*) * (t_nrRows + 1));
	ret = get_next_line(0, line);
	maps.dim_tx = ft_read_dim(maps, line, 1).dim_tx;
	maps.dim_ty = ft_read_dim(maps, line, 1).dim_ty;
	i = 0;
	line = (char**)malloc(sizeof(*line) * maps.dim_tx);
	t_map = (char**)malloc(sizeof(char*) * maps.dim_tx);
	while (i < maps.dim_ty)
	{
		t_map[i] = (char*)malloc(sizeof(char) * maps.dim_ty);
		i++;
	}
	t_nrRows = maps.dim_tx;
	pop_map(line, t_map, t_nrRows, 2);
	maps.t_map = t_map;
	return (maps);
}

void	pop_map(char **line, char **map, int rows, int flag)
{
	int i;
	size_t j;
	int ret;

	i = 0;
	while (i < rows)
	{
		ret = get_next_line(0, line);
		if (flag == 1 || flag == 0)
			*line = *line + 4;
		j = 0;
		while (j < ft_strlen(*line))
		{
			map[i][j] = *(*line + j);
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	map[i] = NULL;
}

void	print_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return ;
}
