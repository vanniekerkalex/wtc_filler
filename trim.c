/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 15:54:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/20 18:23:29 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <unistd.h>

struct token	ft_trim_top(struct maps maps, struct token t);
struct token	ft_trim_bottom(struct maps maps, struct token t);
struct token	ft_trim_left(struct maps maps, struct token t);
struct token	ft_trim_right(struct maps maps, struct token t);

struct token	ft_trim(struct maps maps)
{
	struct token t;

	t.row_top = 0;
	t.row_bottom = 0;
	t.col_left = 0;
	t.col_right = 0;
	t = ft_trim_top(maps, t);
	t = ft_trim_bottom(maps, t);
	t = ft_trim_left(maps, t);
	t = ft_trim_right(maps, t);
	t.dim_x = maps.dim_tx - t.col_left - t.col_right;
	t.dim_y = maps.dim_ty - t.row_top - t.row_bottom;
	/*write(1,"Top: ", 5);
    ft_putnbr(t.row_top);
    write(1,"\nBot: ", 6);
    ft_putnbr(t.row_bottom);
    write(1,"\nLef: ", 6);
    ft_putnbr(t.col_left);
    write(1,"\nRig: ", 6);
    ft_putnbr(t.col_right); */
	return (t);
}

struct token	ft_trim_top(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

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
	return (t);
}

struct token	ft_trim_bottom(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

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
	return (t);
}

struct token	ft_trim_left(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

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
	return (t);
}

struct token	ft_trim_right(struct maps maps, struct token t)
{
	int i;
	int j;
	int count;

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
			break ;
		else
			t.col_right++;
		j--;
	}
	return (t);
}
