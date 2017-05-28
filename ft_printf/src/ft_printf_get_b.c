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

void	ft_printf_get_b(t_mod *conv, va_list args)
{
	if (!(conv->length))
		conv->substring = ft_printf_itoa_binary(va_arg(args, int), sizeof(int));
	else if (ft_printf_strcmp(conv->length, "h") == 0)
		conv->substring = ft_printf_itoa_binary(va_arg(args, int), sizeof(int));
	else if (ft_printf_strcmp(conv->length, "j") == 0)
		conv->substring = ft_printf_itoa_binary(va_arg(args, intmax_t),
													sizeof(uintmax_t));
	else if (ft_printf_strcmp(conv->length, "l") == 0)
		conv->substring = ft_printf_itoa_binary(va_arg(args, long),
													sizeof(long));
	else if (ft_printf_strcmp(conv->length, "hh") == 0)
		conv->substring = ft_printf_itoa_binary(va_arg(args, int), sizeof(int));
}
