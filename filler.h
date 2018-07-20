/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:15 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/20 21:13:00 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

struct maps {
	char **map;
	char **t_map;
	int	dim_x;
	int	dim_y;
	int	dim_tx;
	int	dim_ty;
	char c_piece;
	char e_piece;
	int c_flag;
	int e_flag;
};

struct token {
	int	row_top;
	int	col_left;
	int	row_bottom;
	int	col_right;
	int	dim_x;
	int dim_y;
};

struct score {
	int score;
	int x;
	int y;
};

struct coords {
	int x;
	int y;
};


struct maps			ft_init_map(int nrRows, char **map, char **t_map);
char				**ft_read_map(struct maps maps, int flag, char **map);
struct maps			ft_read_token(struct maps maps, int t_nrRows, char **t_map);
void				print_map(char **map);
struct maps			ft_read_dim(struct maps maps, char **line, int flag);

struct token		ft_trim(struct maps maps);
int					**init_heatmap(struct maps maps);
int					**find_enemy_token(struct maps maps, int **heatmap);
void				print_heatmap(struct maps maps, int **heatmap);
int					check_boundary(struct maps maps, int tx, int ty);
struct score		find_coords(struct maps maps, int **heatmap, struct token token, int fd); //remove fd

#endif
