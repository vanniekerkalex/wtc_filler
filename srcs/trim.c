/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:01:00 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/25 12:01:09 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_trim_top(t_maps *maps, t_token *t);
void	ft_trim_bottom(t_maps *maps, t_token *t);
void	ft_trim_left(t_maps *maps, t_token *t);
void	ft_trim_right(t_maps *maps, t_token *t);

void	ft_trim(t_maps *maps, t_token *t)
{
	t->row_top = 0;
	t->row_bottom = 0;
	t->col_left = 0;
	t->col_right = 0;
	ft_trim_top(maps, t);
	ft_trim_bottom(maps, t);
	ft_trim_left(maps, t);
	ft_trim_right(maps, t);
	t->dim_x = maps->dim_tx - t->col_left - t->col_right;
	t->dim_y = maps->dim_ty - t->row_top - t->row_bottom;
}

void	ft_trim_top(t_maps *maps, t_token *t)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < maps->dim_ty)
	{
		j = 0;
		while (j < maps->dim_tx)
		{
			if (maps->t_map[i][j++] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t->row_top++;
		i++;
	}
}

void	ft_trim_bottom(t_maps *maps, t_token *t)
{
	int i;
	int j;
	int count;

	i = maps->dim_ty - 1;
	count = 0;
	while (i >= 0)
	{
		j = maps->dim_tx - 1;
		while (j >= 0)
		{
			if (maps->t_map[i][j--] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t->row_bottom++;
		i--;
	}
}

void	ft_trim_left(t_maps *maps, t_token *t)
{
	int i;
	int j;
	int count;

	j = 0;
	count = 0;
	while (j < maps->dim_tx)
	{
		i = 0;
		while (i < maps->dim_ty)
		{
			if (maps->t_map[i++][j] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t->col_left++;
		j++;
	}
}

void	ft_trim_right(t_maps *maps, t_token *t)
{
	int i;
	int j;
	int count;

	j = maps->dim_tx - 1;
	count = 0;
	while (j >= 0)
	{
		i = maps->dim_ty - 1;
		while (i >= 0)
		{
			if (maps->t_map[i--][j] != '.')
				count++;
		}
		if (count > 0)
			break ;
		else
			t->col_right++;
		j--;
	}
}
