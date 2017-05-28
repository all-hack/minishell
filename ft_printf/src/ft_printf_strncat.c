/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:58 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:58 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf_strncat(char *s1, unsigned char const *s2, size_t n)
{
	size_t	end;
	size_t	i;

	i = 0;
	end = ft_printf_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[end + i] = s2[i];
		if (s2[i] == 0)
			s2--;
		i++;
	}
	s1[end + i] = 0;
	return (s1);
}
