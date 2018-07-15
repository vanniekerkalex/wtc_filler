/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 12:49:24 by jde-agr           #+#    #+#             */
/*   Updated: 2018/06/18 12:58:17 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_line(int const fd, char *buf, char *saved[fd])
{
	int		ret;
	char	*car;
	char	*tmp;

	while ((car = ft_strchr(buf, '\n')) == NULL &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = saved[fd];
		saved[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	if (ret == -1)
		return (-1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char	*save[MAX_FD];
	char		*buffer;
	int			ret;
	char		*str;
	char		*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buffer == NULL || BUFF_SIZE < 1)
		return (-1);
	if (save[fd] == NULL)
		save[fd] = ft_strnew(0);
	if ((ret = get_line(fd, buffer, save)) == -1)
		return (-1);
	if ((str = ft_strchr(save[fd], '\n')) != NULL)
	{
		*line = ft_strsub(save[fd], 0, str - save[fd]);
		tmp = save[fd];
		save[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(save[fd]);
	ft_strdel(&save[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
