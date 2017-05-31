/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:13:00 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 15:13:01 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	char	*ft_strtrim_nc(char const *s, char *c)
{
	size_t	start;
	size_t	length;
	size_t	index;

	if (s)
	{
		start = 0;
		while (ft_strchri(c, *s, &index))
			s++;
		length = ft_strlen(s);
		if (length > 0)
			while (ft_strchri(c, *(s + length - 1), &index))
				length--;
		return (ft_strsub(s, 0, length));
	}
	return (NULL);
}

static	char	**add_to_strlist(char **strlist, char *s, size_t len)
{
	char	*str;

	str = ft_strsub(s, 0, len);
	strlist = ft_strlist_add(strlist, str);
	ft_strdel(&str);
	return (strlist);
}

char			**msh_blanksplit(char *s, char *c)
{
	size_t	index;
	char	**strlist;
	char	*tmp;
	char	*kill;

	if (s)
	{
		strlist = NULL;
		s = ft_strtrim_nc(s, c);
		kill = s;
		while (ft_stric(s, c, &index))
		{
			if (index > 0)
			{
				strlist = add_to_strlist(strlist, s, index);
				s = s + index;
			}
			else
				s++;
		}
		if (ft_strlen(s) > 0)
			strlist = add_to_strlist(strlist, s, ft_strlen(s));
		ft_strdel(&kill);
		return (strlist);		
	}
	return (NULL);
}
