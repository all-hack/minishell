/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nchr_1sym.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nchr_1sym(char const *s, char const **c, char **s_str)
{
	size_t		i;
	char const	*d;

	if (s && c && *c)
	{
		while (*s)
		{
			i = 0;
			while (c[i])
			{
				d = ft_shiftstr(c[i++], *s_str);
				if (ft_1chr_nsym(s, d, s_str) == 1)
				{
					s++;
					break ;
				}
			}
			s++;
		}
		if (*s_str)
			return (1);
		else
			return (0);
	}
	return (-1);
}
