/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:54:23 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/22 12:21:11 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	//puts("0 0");
	t_maps *maps;
	maps = init_struct();
	t_token *token;
	token = init_struct_token();

	ft_read(maps, 0);
	init_heatmap(maps);

	find_enemy_token(maps);
	ft_trim(maps, token);
	find_coords(maps, token);

	ft_strdel(maps->t_map);

	ft_putnbr(maps->score_y);
	write(1, " ", 1);
	ft_putnbr(maps->score_x);
	write(1, "\n", 1);

	while (1)
	{
		ft_read(maps, 1);
		init_heatmap(maps);
		find_enemy_token(maps);
		ft_trim(maps, token);
		find_coords(maps, token);

		ft_strdel(maps->t_map);

		ft_putnbr(maps->score_y);
		write(1, " ", 1);
		ft_putnbr(maps->score_x);
		write(1, "\n", 1);
	}
	return (0);
}
