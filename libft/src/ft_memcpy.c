/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:56 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:56 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (n > 0)
	{
		i = n - 1;
		while (i > 0)
		{
			((char*)dst)[i] = ((char*)src)[i];
			i--;
		}
		((char*)dst)[i] = ((char*)src)[i];
	}
	return (dst);
}
