/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strappend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf_strappend(char *s1, unsigned char c)
{
	size_t	s1_len;
	size_t	c_len;
	char	*nstr;
	size_t	i;

	if (s1)
		s1_len = ft_printf_strlen(s1);
	else
		s1_len = 0;
	if (c)
		c_len = 1;
	else
		c_len = 0;
	nstr = ft_printf_strnew((s1_len + c_len + 1));
	ft_printf_strncpy(nstr, s1, s1_len);
	ft_printf_strncat(nstr, &c, 1);
	return (nstr);
}
