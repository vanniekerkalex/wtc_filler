/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 16:00:17 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/23 13:41:59 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef	struct	s_maps
{
	char		**map;
	char		**t_map;
	int			**heatmap;
	int			dim_x;
	int			dim_y;
	int			dim_tx;
	int			dim_ty;
	char		c_piece;
	char		e_piece;
	int			c_flag;
	int			e_flag;
	int			score;
	int			score_x;
	int			score_y;
	int			coords_x;
	int			coords_y;
}				t_maps;

typedef struct	s_token
{
	int			row_top;
	int			col_left;
	int			row_bottom;
	int			col_right;
	int			dim_x;
	int			dim_y;
}				t_token;

void			ft_trim(t_maps *maps, t_token *t);
void			init_heatmap(t_maps *maps);
void			find_enemy_token(t_maps *maps);
void			print_heatmap(t_maps *maps);
int				check_boundary(t_maps *maps, int tx, int ty);
void			find_coords(t_maps *maps, t_token *token);
t_maps			*init_struct();
t_token			*init_struct_token();
void			ft_read(t_maps *maps, int flag);
void			ft_read_dim(t_maps *maps, char *line, int flag);

#endif
