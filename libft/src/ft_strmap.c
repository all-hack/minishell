/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 02:44:03 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 02:44:06 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*nstr;
	int		x;

	if (s)
	{
		i = ft_strlen(s);
		NULL_GUARD(nstr = ft_strnew(i));
		x = 0;
		while (*s)
		{
			nstr[x] = f(*s++);
			x++;
		}
		return (nstr);
	}
	return (NULL);
}
