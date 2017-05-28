/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_shiftstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char const	*ft_printf_shiftstr(char const *s1, char const *s2)
{
	unsigned char	c1;
	unsigned char	c2;

	if (s1 && s2)
	{
		while (s1)
		{
			c1 = (unsigned char)*s1;
			c2 = (unsigned char)*s2;
			if (c1 != c2)
				return (s1);
			if (c1 == 0)
				return (s1);
			s1++;
			s2++;
		}
	}
	return (s1);
}
