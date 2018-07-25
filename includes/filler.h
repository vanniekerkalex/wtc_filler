/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 11:57:23 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/25 11:57:42 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

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
