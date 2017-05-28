/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:13:00 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 15:13:01 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcut_c0(char *s, char c)
{
	size_t	start;
	size_t	length;

	if (s)
	{
		start = 0;
		length = ft_strlen(s);
		if (length > 0)
			while (*(s + length - 1) == c)
				s[length--] = '\0';
	}
	return ;
}
