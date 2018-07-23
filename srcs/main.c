/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:13:26 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/23 16:45:30 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

void	do_loop(t_maps *maps, t_token *token);
void	print_map(t_maps *maps, int fd);

int		main(void)
{
	t_maps	*maps;
	t_token	*token;

	maps = init_struct();
	token = init_struct_token();
	ft_read(maps, 0);
	print_map(maps, 2);
	do_loop(maps, token);
	while (1)
	{
		ft_read(maps, 1);
		print_map(maps, 2);
		do_loop(maps, token);
		if (maps->score_x == 0 && maps->score_y == 0 && maps->score == 0)
			break ;
	}
	return (0);
}

void	do_loop(t_maps *maps, t_token *token)
{
	init_heatmap(maps);
	find_enemy_token(maps);
	ft_trim(maps, token);
	find_coords(maps, token);
	ft_strdel(maps->t_map);
	ft_putnbr_fd(maps->score_y, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(maps->score_x, 1);
	ft_putchar_fd('\n', 1);
}

void	print_map(t_maps *maps, int fd)
{
	int i;
	int j;

	i = 0;
	while (i < maps->dim_y)
	{
		j = 0;
		while (j < maps->dim_x)
		{
			if (maps->map[i][j] == 'x' || maps->map[i][j] == 'X')
				ft_putstr_fd(GRN, fd);
			else if (maps->map[i][j] == 'o' || maps->map[i][j] == 'O')
				ft_putstr_fd(RED, fd);
			else
				ft_putstr_fd(RESET, fd);
			ft_putchar_fd(maps->map[i][j], fd);
			j++;
		}
		write(fd, "\n", 1);
		i++;
	}
	write(fd, "\n", 1);
	return ;
}
