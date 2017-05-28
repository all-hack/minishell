/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stri_tail.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:46:48 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 16:46:49 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_stri_tail(char const *s, char c)
{
	size_t	i;
	char	flag;
	int		j;
	int		x;

	flag = 0;
	x = 0;
	j = ft_stri_head(s, c) - 1;
	i = j;
	while (s[++j])
	{
		if (s[j] == c)
		{
			x++;
			flag = 1;
		}
		else if (s[j] != c && flag == 0)
			i++;
		else if (s[j] != c && flag == 1)
		{
			i += (x + 1);
			x = --flag;
		}
	}
	return (i + 1);
}
