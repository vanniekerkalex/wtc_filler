/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:24:06 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/22 16:24:40 by jde-agr          ###   ########.fr       */
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

void	ft_read_player(t_maps *maps)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strncmp(ft_strchr(line, ':') - 2, "1", 1) == 0)
		set_players(maps, 1);
	else
		set_players(maps, 0);
}

void	ft_read_map(t_maps *maps, int flag)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	if (flag == 0)
		ft_read_dim(maps, line, flag);
	get_next_line(0, &line);
	maps->map = (char**)malloc(sizeof(char*) * (maps->dim_y + 1));
	while (i < maps->dim_y)
	{
		maps->map[i] = (char*)malloc(sizeof(char) * (maps->dim_x + 1));
		get_next_line(0, &line);
		line = line + 4;
		j = 0;
		while (j < maps->dim_x)
		{
			maps->map[i][j] = *(line + j);
			j++;
		}
		maps->map[i][j] = '\0';
		i++;
	}
	maps->map[i] = NULL;
}

void	ft_read_token(t_maps *maps, int flag)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	get_next_line(0, &line);
	ft_read_dim(maps, line, flag);
	maps->t_map = (char**)malloc(sizeof(char*) * (maps->dim_ty + 1));
	while (i < maps->dim_ty)
	{
		maps->t_map[i] = (char*)malloc(sizeof(char) * (maps->dim_tx + 1));
		get_next_line(0, &line);
		j = 0;
		while (j < maps->dim_tx)
		{
			maps->t_map[i][j] = *(line + j);
			j++;
		}
		maps->t_map[i][j] = '\0';
		i++;
	}
	maps->t_map[i] = NULL;
}

void	set_players(t_maps *maps, int flag)
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
