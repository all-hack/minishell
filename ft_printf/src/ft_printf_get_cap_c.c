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

void	ft_printf_get_cap_c(t_mod *conv, va_list args)
{
	if (!(conv->length))
		conv->substring = ft_printf_chng_wchar_t(conv,
							va_arg(args, wchar_t), NULL);
	if (conv->substring[0] == '\0')
	{
		conv->substring = ft_printf_strdup("\255");
		conv->skips += 1;
		conv->num = 0;
	}
}
