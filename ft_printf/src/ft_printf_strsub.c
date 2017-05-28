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

#include "libftprintf.h"

char	*ft_printf_strsub(char const *s, size_t start, size_t len)
{
	char	*nstr;

	if (s)
	{
		FT_PRINTF_NULLGUARD(nstr = ft_printf_strnew(len));
		ft_printf_strncat(nstr, ((unsigned char *)s) + start, len);
		return (nstr);
	}
	return (NULL);
}
