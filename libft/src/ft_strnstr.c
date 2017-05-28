/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:59 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:59 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	x;
	int	y;

	if (*little == '\0')
		return ((char*)big);
	x = 0;
	while (*big && x++ < len)
	{
		i = 1;
		j = 0;
		if ((unsigned char)*big == (unsigned char)little[j])
		{
			y = x;
			while (big[i] == little[++j] && little[j] && big[i++] && y < len)
			{
				y++;
			}
			if (little[j] == '\0')
				return ((char*)big);
		}
		big++;
	}
	return (0);
}
