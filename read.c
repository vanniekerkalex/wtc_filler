/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:20:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/16 13:11:33 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void		pop_map(char **line, char **map, int rows, int flag);

struct maps	ft_read_dim(struct maps maps, char **line, int flag)
{
	char	**tmp;

	tmp = ft_strsplit(*line, ' ');
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

char		**ft_read_map(struct maps maps, int flag, char **map)
{
	int		ret;
	int		i;
	char	**line;

	i = 0;
	line = (char**)malloc(sizeof(*line) * maps.dim_y);
	ret = get_next_line(0, line);
	if (flag == 1)
		ret = get_next_line(0, line);
	map = (char**)malloc(sizeof(char*) * (maps.dim_y + 1));
	while (i < maps.dim_y)
	{
		map[i] = (char*)malloc(sizeof(char) * (maps.dim_x + 1));
		i++;
	}
	pop_map(line, map, maps.dim_y, 1);
	return (map);
}

struct maps	ft_read_token(struct maps maps, int t_nrRows, char **t_map)
{
	int		ret;
	int		i;
	char	**line;

	line = (char**)malloc(sizeof(char*) * (t_nrRows + 1));
	ret = get_next_line(0, line);
	maps = ft_read_dim(maps, line, 1);
	//maps.dim_ty = ft_read_dim(maps, line, 1).dim_ty;
	//maps.dim_tx = ft_read_dim(maps, line, 1).dim_tx;
	i = 0;
	line = (char**)malloc(sizeof(*line) * (maps.dim_ty + 1));
	t_map = (char**)malloc(sizeof(char*) * (maps.dim_ty + 1));
	while (i < maps.dim_tx)
	{
		t_map[i] = (char*)malloc(sizeof(char) * (maps.dim_tx + 1));
		i++;
	}
	t_nrRows = maps.dim_ty;
	pop_map(line, t_map, t_nrRows, 2);
	maps.t_map = t_map;
	return (maps);
}

void		pop_map(char **line, char **map, int rows, int flag)
{
	int		i;
	size_t	j;
	int		ret;

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

void		print_map(char **map)
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
