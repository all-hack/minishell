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

static	char	*read_til_line(const int fd, char **line, size_t *back)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	bzero(buff, sizeof(char) * BUFF_SIZE + 1);
	ret = 1;
	tmp = NULL;
	while (ft_strchr(buff, '\n') == NULL && ret > 0)
	{
		bzero(buff, sizeof(char) * BUFF_SIZE + 1);		
		ret = read(fd, buff, BUFF_SIZE);
		tmp = ft_fstrmcat(tmp, buff);		
	}
	if (*tmp == 0 && ret == 0)
		*back = 0;
	else
		*back = 1;
	return (tmp);
}

static	char	*remain_to_line(char **remain, char **line)
{
	char *tmp;
	char *left;

	tmp = ft_strchr(*remain, '\n');
	*line = ft_strsub(*remain, 0, tmp - (*remain));
	if (*(tmp + 1) == 0)
		return (NULL);
	else
		return (ft_strdup(tmp + 1));
}

int				get_next_line(const int fd, char **line)
{
	static char	*remain;
	char		*tmp;
	size_t		index;

	FGUARD(read(fd, "", 0));
	if (ft_stric(remain, "\n", &index) > 0)
	{
		tmp = remain_to_line(&remain, line);
		ft_strdel(&remain);
		remain = tmp;
		return (1);
	}
	else
	{		
		remain = ft_fstrmcatf(remain, read_til_line(fd, line, &index));
		if (index == 0)
		{			
			ft_strdel(&remain);
			return (index);
		}
		tmp = remain_to_line(&remain, line);
		ft_strdel(&remain);
		remain = tmp;
		return (index);
	}
}
