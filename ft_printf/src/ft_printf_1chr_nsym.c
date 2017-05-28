/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1chr_nsym.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_1chr_nsym(char const *s, char const *c, char **s_str)
{
	size_t	i;
	size_t	j;
	int		flag;

	flag = -1;
	if (s && c)
	{
		if (s_str)
		{
			i = 0;
			flag = 0;
			while (s[i])
			{
				if ((ft_printf_strchri(c, s[i++], &j)) == 1)
				{
					*s_str = ft_printf_fstrappend(*s_str, c[j]);
					flag = 1;
				}
				else
					return (flag);
			}
			return (flag);
		}
	}
	return (flag);
}
