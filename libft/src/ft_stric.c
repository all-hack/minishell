/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stri_delim.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:35:48 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 17:35:51 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stric(char const *s, char const *c, size_t *index)
{
	size_t	i;
	size_t	j;

	if (s && c)
	{
		i = 0;
		while (s[i])
		{
			j = -1;
			while (c[++j])
				if (s[i] == c[j])
				{
					*index = i;
					return (1);
				}
			i++;
		}
		return (0);
	}
	return (-1);
}
