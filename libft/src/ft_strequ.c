/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 15:21:25 by obelange          #+#    #+#             */
/*   Updated: 2016/10/17 16:40:08 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	if (s1)
	{
		i = 0;
		while (s1[i] && s2[i])
		{
			c1 = (unsigned char)s1[i];
			c2 = (unsigned char)s2[i++];
			if (c1 > c2)
				return (0);
			else if (c1 < c2)
				return (0);
		}
		c1 = (unsigned char)s1[i];
		c2 = (unsigned char)s2[i];
		if (c1 > c2)
			return (0);
		else if (c1 < c2)
			return (0);
		return (1);
	}
	return (0);
}
