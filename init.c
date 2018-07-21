/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:35:29 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/21 13:06:54 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct maps set_players(struct maps maps, int flag);

struct maps		ft_player(char **line, struct maps maps)
{
	int ret;

	ret = get_next_line(0, line);
	while (ft_strncmp("$$$ exec p", *line, 10) != 0)
		ret = get_next_line(0, line);
	if (ft_strncmp(ft_strchr(*line, ':') - 2, "1", 1) == 0)
		maps = set_players(maps, 1);
	else
		maps = set_players(maps, 0);
	return (maps);
}

struct maps	ft_init_map(struct maps maps)
{
	int			ret;
	char		**line;

	line = NULL;
	maps.c_piece = '\0';
	line = (char**)malloc(sizeof(*line) * 1);
	maps = ft_player(line, maps);
	ret = get_next_line(0, line); //Plateau
	maps.map = NULL;
	maps.t_map = NULL;
	maps = ft_read_dim(maps, line, 0);
	maps = ft_read_map(maps, 0);
	maps = ft_read_token(maps);
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
