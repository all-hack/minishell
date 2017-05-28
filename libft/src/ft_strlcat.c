/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:58 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:58 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	int		i;
	int		j;
	size_t	dst_len;

	i = -1;
	j = 0;
	dst_len = ft_strlen(dst);
	if (dst_len > size)
		dst_len = size;
	while (dst[j])
		j++;
	while (src[++i] && dst_len + i < size - 1)
		dst[j++] = src[i];
	if (*dst)
		dst[j] = '\0';
	return (dst_len + ft_strlen(src));
}
