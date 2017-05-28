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

void	ft_printf_get_p(t_mod *conv, va_list args)
{
	char *tmp;
	char *hex;

	hex = "0x";
	conv->substring = ft_printf_itoa_base(va_arg(args,
											unsigned long long), 16, 0);
	tmp = conv->substring;
	conv->substring = ft_printf_strmcat(hex, conv->substring);
	ft_printf_strdel(&tmp);
}
