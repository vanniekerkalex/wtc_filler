/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:06:15 by jde-agr           #+#    #+#             */
/*   Updated: 2018/07/16 14:31:37 by avan-ni          ###   ########.fr       */
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

struct token	ft_trim(struct maps maps);

#endif
