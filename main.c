/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 09:07:26 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/20 22:23:23 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <fcntl.h>
int	main(void)
{
	//char **map = NULL;
	//char **t_map = NULL;
	struct maps maps;
	//struct maps tmp;
	struct score score;
	int fd = open("coords.txt", O_WRONLY);

	//int i = 0;
	//int j = 0;
	//map = NULL;
	write(fd, "init map\n", 9);
	maps = ft_init_map(0, maps.map, maps.t_map);
	//printf("\n*****MAP*****\n");
	//print_map(maps.map);
	//printf("\n*****TOKEN*****\n");
	//print_map(maps.t_map);
	//ft_trim(maps); // Testing Trim.c
	int **heat;
	//printf("\n*****INIT HEAT*****\n");
	write(fd, "init heat\n", 10);
	heat = init_heatmap(maps);
	//print_heatmap(maps, heat);
	//printf("\n*****HEATMAP*****\n");
	write(fd, "enem\n", 5);
	heat = find_enemy_token(maps, heat);
	print_heatmap(maps, heat);
	write(fd, "coords ", 7);
	score = find_coords(maps, heat, ft_trim(maps),fd);
	ft_putnbr(score.y);
	write(1, " ", 1);
	ft_putnbr(score.x);
	write(1, "\n", 1);
	ft_strdel(maps.map);
	ft_strdel(maps.t_map);
	/*i = 0;
	while (i < maps.dim_y)
	{
		//j = 0;
		//while (j < maps.dim_x)
		//{
			int* currentIntPtr = heat[i];
			free(currentIntPtr);
			j++;
		//}
		i++;
	}
	free(heat);*/
//	printf("MAP\nX : %i\nY : %i\nTOKEN\nX : %i\nY : %i\n", maps.dim_x, maps.dim_y, maps.dim_tx, maps.dim_ty);
	while (1)
	{
		maps.map = ft_read_map(maps, 1, maps.map);
		maps = ft_read_token(maps, 2, maps.t_map);
	    //maps.t_map = tmp.t_map;
	    //maps.dim_ty = tmp.dim_ty;
	    //maps.dim_tx = tmp.dim_tx;
		//printf("\n*****MAP*****\n");
	    //print_map(maps.map);
	    //printf("\n*****TOKEN*****\n");
	    //print_map(maps.t_map);
		ft_trim(maps); // Testing Trim.c
		//printf("\n*****INIT HEAT*****\n");
		heat = init_heatmap(maps);
		//print_heatmap(maps, heat);
		//printf("\n*****HEATMAP*****\n");
		heat = find_enemy_token(maps, heat);
		//print_heatmap(maps, heat);
		score = find_coords(maps, heat, ft_trim(maps), fd);
		ft_putnbr(score.y);
		write(1, " ", 1);
		ft_putnbr(score.x);
		write(1, "\n", 1);
		//ft_strdel(maps.map);
		//ft_strdel(maps.t_map);
		/*i = 0;
		while (i < maps.dim_y)
		{
			//j = 0;
			//while (j < maps.dim_x)
			//{
    			int* currentIntPtr = heat[i];
    			free(currentIntPtr);
				j++;
			//}
			i++;
		}
		free(heat);*/
		//i++;
	}
	close(fd);
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
