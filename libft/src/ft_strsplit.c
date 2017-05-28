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

#include "libft.h"

char			*ft_strtrim_c(char const *s, char c)
{
	size_t	start;
	size_t	length;

	if (s)
	{
		start = 0;
		while (*s == c)
			s++;
		length = ft_strlen(s);
		if (length > 0)
			while (*(s + length - 1) == c)
				length--;
		return (ft_strsub(s, 0, length));
	}
	return (NULL);
}

static	char	**form_charcharchar(char const *s, char c, size_t *k)
{
	size_t		index;
	char const	*str;
	char		**nstr;

	*k = 1;
	str = s;
	while (ft_strchri(str, c, &index))
	{
		str = ft_strchr(str, c);
		str++;
		*k += 1;
	}
	index = 0;
	if ((nstr = (char**)malloc(sizeof(char*) * (*k + 1))))
		while (index <= *k)
			nstr[index++] = NULL;
	else
		return (NULL);
	return (nstr);
}

static	char	**ft_charstr_del(char ***str)
{
	char	*tmp;
	char	**tmp1;

	if (str && *str)
	{
		tmp1 = *str;
		while (**str)
		{
			tmp = **str;
			ft_strdel(&tmp);
			(*str)++;
		}
		free(tmp1);
		str = NULL;
	}
	return (NULL);
}

char			**ft_strsplit(char *s, char c)
{
	size_t	index;
	char	**nstr;
	size_t	size;
	size_t	k;
	char	*x;

	if (s)
	{
		s = ft_strtrim_c(s, c);
		x = s;
		index = 0;
		nstr = form_charcharchar(s, c, &size);
		k = 0;
		while (ft_strchri(s, c, &index))
		{
			if ((nstr[k++] = ft_strsub(s, 0, index)) == NULL)
				return (ft_charstr_del(&nstr));
			s = ft_strchr(s, c) + 1;
		}
		if ((nstr[size - 1] = ft_strsub(s, 0, ft_strlen(s))) == NULL)
			return (ft_charstr_del(&nstr));
		ft_strdel(&x);
		return (nstr);
	}
	return (NULL);
}
