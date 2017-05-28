/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:56 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:56 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			if (((unsigned char *)s)[i] == (unsigned char)c)
				return ((char*)&s[i]);
			i++;
		}
	}
	return (0);
}
