/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 03:14:30 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 03:14:33 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			nstr[x] = f(x, *s++);
			x++;
		}
		return (nstr);
	}
	return (NULL);
}
