/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:57 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:57 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
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
	return (nstr);
}
