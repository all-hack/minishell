/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fstrappend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrdup(char *s0, const char *s1)
{
	size_t	i;
	char	*nstr;
	int		x;

	i = ft_strlen(s1);
	NULL_GUARD(nstr = ft_strnew(i));
	x = 0;
	while (s1[x])
	{
		nstr[x] = s1[x];
		x++;
	}
	ft_strdel(&s0);
	return (nstr);
}
