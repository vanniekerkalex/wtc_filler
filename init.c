/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:35:29 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/18 18:13:11 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct maps		ft_player(char **line, struct maps maps)
{
	int ret;

	ret = get_next_line(0, line);
	while (ft_strncmp("$$$ exec p", *line, 10) != 0)
		ret = get_next_line(0, line);
	if (ft_strncmp(ft_strchr(*line, ':') - 2, "1", 1) == 0)
		maps.c_piece = 'o';
	else
		maps.c_piece = 'x';
	//write(1, "hi", 2);		//just to see
	//write(1, &maps.c_piece, 1);	//if piece is 'o' or 'x'
	return (maps);
}

struct maps	ft_init_map(int nrRows, char **map, char **t_map)
{
	int			ret;
	char		**line;
	struct maps	maps;

	line = NULL;
	maps.c_piece = '\0';
	line = (char**)malloc(sizeof(*line) * 1);
	maps = ft_player(line, maps);
	ret = get_next_line(0, line); //Plateau
	maps.map = NULL;
	maps.t_map = NULL;
	maps = ft_read_dim(maps, line, 0);
	maps.map = ft_read_map(maps, 0, map);
	maps = ft_read_token(maps, nrRows, t_map);
	return (maps);
}
