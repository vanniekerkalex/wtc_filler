/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:15 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/18 13:09:54 by jde-agr          ###   ########.fr       */
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
};

struct token {
	int	row_top;
	int	col_left;
	int	row_bottom;
	int	col_right;
};


struct maps			ft_init_map(int nrRows, char **map, char **t_map);
char				**ft_read_map(struct maps maps, int flag, char **map);
struct maps			ft_read_token(struct maps maps, int t_nrRows, char **t_map);
void				print_map(char **map);
struct maps			ft_read_dim(struct maps maps, char **line, int flag);

struct token		ft_trim(struct maps maps);
int					**init_heatmap(struct maps maps);
int					**find_enemy_token(struct maps maps, int **heatmap, char c_piece);
void				print_heatmap(struct maps maps, int **heatmap);

#endif
