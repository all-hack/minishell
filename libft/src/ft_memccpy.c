/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:56 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:56 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t i;

	if (n > 0)
	{
		i = 0;
		while (i < n)
		{
			((char*)dst)[i] = ((char*)src)[i];
			if (((unsigned char *)src)[i] == (unsigned char)c)
				return (&dst[i + 1]);
			i++;
		}
	}
	return (0);
}
