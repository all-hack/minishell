/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:13:10 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 14:13:12 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf_putstr(char const *s, t_mod *conv)
{
	size_t	len;
	char	*str;

	len = 0;
	str = (char*)s;
	if (s)
	{
		len += ft_printf_strlen(s);
		while (*s)
		{
			if (*s == '\255')
				write(1, "\0", 1);
			else
				write(1, s, 1);
			s++;
		}
	}
	ft_printf_strdel(&str);
	ft_printf_free_struct(&conv);
	return (len);
}
