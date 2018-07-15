/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:54:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/15 16:59:49 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

struct token	ft_trim_top(struct maps maps)
{
	int i;
	int j;
	int count;
	struct token t;

	t.row_top = 0;
	i = 0;
	count = 0;
	while (i < maps.dim_ty)
	{
		j = 0;
		while (j < maps.dim_tx)
		{
			if (maps.t_map[i][j++] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t.row_top++;
		i++;
	}
	ft_trim_bottom(maps, t);
	ft_trim_left(maps, t);
	ft_trim_right(maps, t);
	return (t);
}

void			t_trim_bottom(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

	t.row_bottom = 0;
	i = maps.dim_ty - 1;
	count = 0;
	while (i >= 0)
	{
		j = maps.dim_tx - 1;
		while (j >= 0)
		{
			if (maps.t_map[i][j--] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t.row_bottom++;
		i--;
	}
}

void			ft_trim_left(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

	t.col_left = 0;
	j = 0;
	count = 0;
	while (j < maps.dim_tx)
	{
		i = 0;
		while (i < maps.dim_ty)
		{
			if (maps.t_map[i++][j] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t.col_left++;
		j++;
	}
}

void			ft_trim_right(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

	t.col_right = 0;
	j = maps.dim_tx - 1;
	count = 0;
	while (j >= 0)
	{
		i = maps.dim_ty - 1;
		while (i >= 0)
		{
			if (maps.t_map[i--][j] != '.')
				count++;
		}
		if (count > 0)
			return (t);
		else
			t.col_right++;
		j--;
	}
}
