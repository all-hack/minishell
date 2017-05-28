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

void	ft_printf_get_d(t_mod *conv, va_list args)
{
	if (!(conv->length))
		ft_printf_chng_int(conv, va_arg(args, int));
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		ft_printf_chng_short(conv, va_arg(args, int));
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		ft_printf_chng_intmax_t(conv, va_arg(args, intmax_t));
	else if (ft_printf_strcmp(conv->length, "l") == 0)
		ft_printf_chng_long(conv, va_arg(args, long));
	else if (ft_printf_strcmp(conv->length, "z") == 0)
		ft_printf_chng_longlong(conv, va_arg(args, long long));
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		ft_printf_chng_char(conv, va_arg(args, int));
	else if (ft_printf_strcmp(conv->length, "ll") == 0)
		ft_printf_chng_longlong(conv, va_arg(args, long long));
}
