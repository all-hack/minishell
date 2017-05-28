/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:56 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:56 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (len > 0)
	{
		if (dst >= src)
		{
			i = len - 1;
			while (i > 0)
			{
				((char*)dst)[i] = ((char*)src)[i];
				i--;
			}
			((char*)dst)[i] = ((char*)src)[i];
		}
		else
		{
			i = 0;
			while (i < len)
			{
				((char*)dst)[i] = ((char*)src)[i];
				i++;
			}
		}
	}
	return (dst);
}
