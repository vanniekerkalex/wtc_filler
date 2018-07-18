/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:07:26 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/18 13:59:52 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
int	main(void)
{
	int nrRows;
	char **map = NULL;
	char **t_map = NULL;
	struct maps maps;
	struct maps tmp;

	int i = 0;
	nrRows = 0;
	map = NULL;
	maps = ft_init_map(nrRows, map, map);
	printf("\n*****MAP*****\n");
	print_map(maps.map);
	printf("\n*****TOKEN*****\n");
	print_map(maps.t_map);
	ft_trim(maps); // Testing Trim.c
	int **heat;
	printf("\n*****INIT HEAT*****\n");
	heat = init_heatmap(maps);
	print_heatmap(maps, heat);
	printf("\n*****HEATMAP*****\n");
	heat = find_enemy_token(maps, heat, 'x');
	print_heatmap(maps, heat);
//	printf("MAP\nX : %i\nY : %i\nTOKEN\nX : %i\nY : %i\n", maps.dim_x, maps.dim_y, maps.dim_tx, maps.dim_ty);
	while (i < 2)
	{
		maps.map = ft_read_map(maps, 1, map);
		tmp = ft_read_token(maps, 2, t_map);
	    maps.t_map = tmp.t_map;
	    maps.dim_ty = tmp.dim_ty;
	    maps.dim_tx = tmp.dim_tx;
		printf("\n*****MAP*****\n");
	    print_map(maps.map);
	    printf("\n*****TOKEN*****\n");
	    print_map(maps.t_map);
		ft_trim(maps); // Testing Trim.c
		printf("\n*****INIT HEAT*****\n");
		heat = init_heatmap(maps);
		print_heatmap(maps, heat);
		printf("\n*****HEATMAP*****\n");
		heat = find_enemy_token(maps, heat, 'x');
		print_heatmap(maps, heat);
		maps.map = NULL;
		maps.t_map = NULL;
		i++;
	}
//	print_map(map);
//	write(1, "yo", 2);
//	tmp = ft_read_token(maps, nrRows, t_map);
//	maps.t_map = tmp.t_map;
/*	while (1)
	{
		ft_read_map(nrRows, 1, map);
		ft_read_token(nrRows, t_map);
		//printf("<got (O) : [7 24] (7,24)\n");
	}*/
}
