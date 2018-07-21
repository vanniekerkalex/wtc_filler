/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:15 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/21 20:44:06 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

struct maps {
	char **map;
	char **t_map;
	int **heatmap;
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


//struct maps			ft_init_map(struct maps maps);
//struct maps			ft_read_map(struct maps maps, int flag);
//struct maps			ft_read_token(struct maps maps);
//void				print_map(char **map);
//struct maps			ft_read_dim(struct maps maps, char **line, int flag);

struct token		ft_trim(struct maps maps);
struct maps			init_heatmap(struct maps maps);
struct maps			find_enemy_token(struct maps maps);
void				print_heatmap(struct maps maps);
int					check_boundary(struct maps maps, int tx, int ty);
struct score		find_coords(struct maps maps, struct token token);


struct maps			init_struct(struct maps maps);
struct maps			ft_read(struct maps maps, int flag);

#endif
