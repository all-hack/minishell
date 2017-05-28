/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 04:02:13 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 04:02:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*nstr;

	if (s)
	{
		NULL_GUARD(nstr = ft_strnew(len));
		ft_strncat(nstr, s + start, len);
		return (nstr);
	}
	return (NULL);
}
