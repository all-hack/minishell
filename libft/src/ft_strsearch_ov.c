/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsearch_ov.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 07:18:08 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 07:18:14 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive_loop(char const s, char const *c)
{
	if (c)
	{
		while (*c)
			if (s == *c++)
				return (1);
		return (0);
	}
	return (-1);
}

/*
**	makes sure that string s only contains characters in alphabet c
**	can also be used to make sure that string c does not contain
**		any chr in alphabet s
**			ft_strsearch_ov("-", str) == 0
*/

int			ft_strsearch_ov(char const *s, char const *c)
{
	if (s && c)
	{
		if (recursive_loop(*s, c) == 0)
			return (0);
		while (*++s)
			if (recursive_loop(*s, c) == 0)
				return (0);
		return (1);
	}
	return (-1);
}
