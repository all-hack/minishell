/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:58 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:58 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int				i;
	int				j;
	unsigned char	c1;
	unsigned char	c2;

	if (*little == '\0')
		return ((char*)big);
	while (*big)
	{
		i = 1;
		j = 0;
		c1 = (unsigned char)*big;
		c2 = (unsigned char)little[j];
		if (c1 == c2)
		{
			while (big[i] == little[++j] && little[j] && big[i])
			{
				i++;
			}
			if (little[j] == '\0')
				return ((char*)big);
		}
		big++;
	}
	return (0);
}
