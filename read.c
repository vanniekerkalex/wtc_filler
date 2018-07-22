/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:56:42 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/22 13:37:24 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_read_player(t_maps *maps);
void	ft_read_map(t_maps *maps, int flag);
void	ft_read_token(t_maps *maps, int flag);
void	set_players(t_maps *maps, int flag);

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
	//ft_strdel(&line);
}

void	ft_read_map(t_maps *maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Plateau
	if (flag == 0)
		ft_read_dim(maps, line, flag);
	//ft_strdel(&line);
	get_next_line(0, &line); // numbers
	//ft_strdel(&line);

	maps->map = (char**)malloc(sizeof(char*) * (maps->dim_y + 1));
	while (i < maps->dim_y)
	{
		maps->map[i] = (char*)malloc(sizeof(char) * (maps->dim_x + 1));
		i++;
	}
	write(2,"before pop_map\n",15);
	maps->map = ft_pop_map(maps->map, maps->dim_y, flag);
	write(2,"after pop_map\n",14);
}

void	ft_read_token(t_maps *maps, int flag)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(0, &line); //Piece
	ft_read_dim(maps, line, flag);

	//ft_strdel(&line);

	maps->t_map = (char**)malloc(sizeof(char*) * (maps->dim_ty + 1));
	while (i < maps->dim_ty)
	{
		maps->t_map[i] = (char*)malloc(sizeof(char) * (maps->dim_tx + 1));
		i++;
	}
	write(2,"t: before pop_map\n",18);
	maps->t_map = ft_pop_map(maps->t_map, maps->dim_ty, flag);
	write(2,"t: after pop_map\n",17);
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
