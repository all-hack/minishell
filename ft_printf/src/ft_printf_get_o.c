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

void	ft_printf_get_o(t_mod *conv, va_list args)
{
	if (!(conv->length))
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, uintmax_t), 8, 0);
	else if (ft_printf_strcmp(conv->length, "l") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args,
												unsigned long), 8, 0);
	else if (ft_printf_strcmp(conv->length, "z") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, size_t), 8, 0);
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args, unsigned int), 8, 0);
	else if (ft_printf_strcmp(conv->length, "ll") == 0)
		conv->substring = ft_printf_itoa_base(va_arg(args,
												unsigned long long), 8, 0);
}
