/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strchri.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	norm_cheat00(t_mod *conv, wchar_t chr, char *str)
{
	str = ft_printf_strnew(4);
	str[0] = (char)(((chr >> 18 | 0370) ^ 0370) | 0360);
	str[1] = (char)(((chr >> 12 | 0300) ^ 0300) | 0200);
	str[2] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
	str[3] = (char)(((chr | 0300) ^ 0300) | 0200);
}

static	void	norm_cheat01(t_mod *conv, wchar_t chr, char *str)
{
	chr = 0177775;
	str = ft_printf_strnew(3);
	str[0] = (char)(((chr >> 12 | 0360) ^ 0360) | 0340);
	str[1] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
	str[2] = (char)(((chr | 0300) ^ 0300) | 0200);
}

char			*ft_printf_chng_wchar_t(t_mod *conv, wchar_t chr, char *str)
{
	if (chr < 0200)
	{
		str = ft_printf_strnew(1);
		str[0] = (char)chr;
	}
	else if (chr >= 0200 && chr <= 03777)
	{
		str = ft_printf_strnew(2);
		str[0] = (char)(((chr >> 6 | 0340) ^ 0340) | 0300);
		str[1] = (char)(((chr | 0300) ^ 0300) | 0200);
	}
	else if (chr >= 04000 && chr <= 0177777)
	{
		str = ft_printf_strnew(3);
		str[0] = (char)(((chr >> 12 | 0360) ^ 0360) | 0340);
		str[1] = (char)(((chr >> 6 | 0300) ^ 0300) | 0200);
		str[2] = (char)(((chr | 0300) ^ 0300) | 0200);
	}
	else if (chr >= 0200000 && chr <= 04177777)
		norm_cheat00(conv, chr, str);
	else
		norm_cheat01(conv, chr, str);
	return (str);
}
