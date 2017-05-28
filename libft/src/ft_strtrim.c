/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 12:33:13 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 12:33:17 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	length;

	if (s)
	{
		start = 0;
		while (ft_isnt32(s[start]))
			start++;
		length = ft_strlen(s + start);
		if (length > 0)
			while (ft_isnt32(s[start + length - 1]))
				length--;
		return (ft_strsub(s, start, length));
	}
	return (NULL);
}
