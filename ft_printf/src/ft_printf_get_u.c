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

void	ft_printf_get_u(t_mod *conv, va_list args)
{
	if (!(conv->length))
		ft_printf_chng_uint(conv, va_arg(args, unsigned int));
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		ft_printf_chng_ushort(conv, va_arg(args, unsigned int));
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		ft_printf_chng_uintmax_t(conv, va_arg(args, uintmax_t));
	else if (ft_printf_strcmp(conv->length, "l") == 0)
		ft_printf_chng_ulong(conv, va_arg(args, unsigned long));
	else if (ft_printf_strcmp(conv->length, "z") == 0)
		ft_printf_chng_size_t(conv, va_arg(args, size_t));
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		ft_printf_chng_uchar(conv, va_arg(args, unsigned int));
	else if (ft_printf_strcmp(conv->length, "ll") == 0)
		ft_printf_chng_ulonglong(conv, va_arg(args, unsigned long long));
}
