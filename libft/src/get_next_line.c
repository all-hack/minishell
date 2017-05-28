/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:16 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:18 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	line_in_buffer(char **line, char **remain, char const *c)
{
	char	*chr;
	char	*tmp;
	size_t	i_of_n;
	size_t	size;

	chr = ft_strchr(*remain, '\n');
	if (ft_stric(*remain, c, &i_of_n) == 0)
		i_of_n = ft_strlen(*remain);
	NULLGUARD(*line = ft_strsub(*remain, 0, i_of_n));
	tmp = *remain;
	if (chr)
	{
		size = ft_strlen(chr);
		NULLGUARD(*remain = ft_strsub(*remain, ++i_of_n, size));
		ft_strdel(&tmp);
	}
	return (1);
}

static	int	line_out_buffer(const int fd, char **remain, int *status)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		stat;
	int		x;

	stat = -1;
	ft_bzero(buff, BUFF_SIZE);
	if ((x = read(fd, buff, BUFF_SIZE) > 0))
	{
		stat = 1;
		tmp = *remain;
		*remain = ft_strmcat(*remain, buff);
		ft_strdel(&tmp);
		return (stat);
	}
	if (!*remain)
		return (-1);
	if ((*remain)[0])
	{
		*status = 0;
		return (2);
	}
	return (0);
}

static	int	new_elem(t_line_elem **elem, const int fd)
{
	if (!(*elem) || ((*elem) && (*elem)->fd != fd))
	{
		if (!(*elem))
			NULLGUARD(*elem = (t_line_elem*)malloc(sizeof(t_line_elem)));
		(*elem)->fd = fd;
		((*elem)->st)[0] = -1;
		((*elem)->index) = 0;
		((*elem)->st)[1] = -1;
		(*elem)->delim = "\n";
		(*elem)->re = NULL;
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_line_elem *e;

	FILEGUARD(new_elem(&e, fd));
	if (fd > -1 && line)
	{
		if ((e->st)[0]-- == 0)
		{
			ft_bzero(*line, ft_strlen(*line));
			return (0);
		}
		while (ft_stric(e->re, e->delim, &(e->index)) < 1)
		{
			FILEGUARD((e->st)[1] = line_out_buffer(fd, &(e->re), &(e->st)[0]));
			if ((e->st)[1] == 0)
			{
				ft_bzero(*line, ft_strlen(*line));
				break ;
			}
			else if ((e->st)[1] == 2)
				return (line_in_buffer(line, &(e->re), e->delim));
		}
		if (ft_stric(e->re, e->delim, &(e->index)) == 1)
			return (line_in_buffer(line, &(e->re), e->delim));
	}
	return ((e->st)[1]);
}
