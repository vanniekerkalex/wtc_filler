/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 17:54:23 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/21 20:45:06 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	//puts("0 0");
	struct maps maps;
	struct score score;
	struct token token;

	maps = init_struct(maps);
	maps = ft_read(maps, 0);
	maps = init_heatmap(maps);

	maps = find_enemy_token(maps);
	token = ft_trim(maps);
	score = find_coords(maps, token);

	ft_strdel(maps.t_map);
	ft_strdel(maps.map);

	ft_putnbr(score.y);
	write(1, " ", 1);
	ft_putnbr(score.x);
	write(1, "\n", 1);
	while (1)
	{
		maps = ft_read(maps, 1);
		maps = init_heatmap(maps);
		maps = find_enemy_token(maps);
		token = ft_trim(maps);
		score = find_coords(maps, token);//, fd);

		ft_strdel(maps.t_map);
		ft_strdel(maps.map);


		ft_putnbr(score.y);
		write(1, " ", 1);
		ft_putnbr(score.x);
		write(1, "\n", 1);
	}
	return (0);
}
