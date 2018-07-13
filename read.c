/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:20:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/13 14:57:30 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

/*
**
**Comment
**
*/

struct maps	ft_read_dim(struct maps maps, char **line, int flag)
{
	char    *ptr;
	char    *ptr2;
	char    *ptr3;
	char    *num;
	char    *num2;

    ptr = ft_strchr(*line, ' ');
    ptr2 = ft_strchr(ptr + 1, ' ');
    ptr3 = ft_strchr(ptr2 + 1, '\0');
    num = ft_strsub(ptr + 1, 0, ptr2 - ptr - 1);
    num2 = ft_strsub(ptr2 + 1, 0, ptr3 - ptr2 - 1);
	if (flag == 0)
	{
		maps.dim_x = ft_atoi(num);
		maps.dim_y = ft_atoi(num2);
	}
	else
	{
		maps.dim_tx = ft_atoi(num);
		maps.dim_ty = ft_atoi(num2);
	}
	return (maps);
}

struct maps		ft_init_map(int nrRows, char **map, char **t_map)
{
	int		ret;
	char	**line;
	char	*p1;
	char	*p2;
	char	*c_piece;
	char	*name;
	struct maps maps;
	struct maps tmp;
	struct maps tmp2;

	line = (char**)malloc(sizeof(*line) * 1);
	ret = get_next_line(0, line);
	while (ft_strncmp("$$$ exec p1", *line, 11) != 0)
		ret = get_next_line(0, line);
	p1 = ft_strchr(*line, ':') + 2;
	printf("player 1 : %s\n", p1);
	//ret = get_next_line(0, line);
	while (ft_strncmp("$$$ exec p2", *line, 11) != 0)
		ret = get_next_line(0, line);
	p2 = ft_strchr(*line, ':') + 2;
	printf("player 2 : %s\n", p2);

	name = " hiu ";
	if (name == p1)
		c_piece = "o";
	else
		c_piece = "x";

	ret = get_next_line(0, line);
	maps.map = NULL;
	tmp = ft_read_dim(maps, line, 0);
	maps.dim_x = tmp.dim_x;
	maps.dim_y = tmp.dim_y;
	maps.map = ft_read_map(maps, 0, map);
	tmp2 = ft_read_token(maps, nrRows, t_map);
	maps.t_map = tmp2.t_map;
	maps.dim_tx = tmp2.dim_tx;
	maps.dim_ty = tmp2.dim_ty;
	return (maps);
}

char	**ft_read_map(struct maps maps, int flag, char **map)
{
	int		ret;
	int		i;
	size_t	j;
	char	**line;

	i = 0;
	line = (char**)malloc(sizeof(*line) * maps.dim_x);
	ret = get_next_line(0, line); //bunch of nums at beginning
	if (flag == 1)
		ret = get_next_line(0, line);
    map = (char**)malloc(sizeof(char*) * (maps.dim_x + 1));
    while (i < maps.dim_x)
    {
        map[i] = (char*)malloc(sizeof(char) * (maps.dim_y + 1));
        i++;
	}
	i = 0;
	while (i < maps.dim_x)
	{
		ret = get_next_line(0, line);
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
	return (map);
}

struct maps		ft_read_token(struct maps maps, int t_nrRows, char **t_map)
{
	int		ret;
	int		i;
	size_t	j;
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
	i = 0;
	while (i < t_nrRows)
	{
		ret = get_next_line(0, line);
		j = 0;
		while (j < ft_strlen(*line))
		{
			t_map[i][j] = *(*line + j);
			j++;
		}
		t_map[i][j] = '\0';
		i++;
	}
	t_map[i] = NULL;
	maps.t_map = t_map;
	return (maps);
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
