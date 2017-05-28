/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtbl.h"

int		hash_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

void	hash_strdel(char **as)
{
	if (as)
	{
		if (*as)
		{
			free(*as);
			*as = 0;
		}
	}
}

int		hash_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] && s2[i])
	{
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 > c2)
			return (c1 - c2);
		else if (c1 < c2)
			return (c1 - c2);
		i++;
	}
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	if (c1 > c2)
		return (c1 - c2);
	else if (c1 < c2)
		return (c1 - c2);
	return (0);
}

char	*hash_strdup(char *s1)
{
	size_t	i;
	char	*nstr;
	int		x;

	i = hash_strlen(s1);
	NULL_GUARD(nstr = hash_strnew(i));
	x = 0;
	while (s1[x])
	{
		nstr[x] = s1[x];
		x++;
	}
	return (nstr);
}

char	*hash_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		str[size] = 0;
		return (str);
	}
	else
		return (0);
}
