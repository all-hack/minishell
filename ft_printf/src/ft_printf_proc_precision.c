/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:09 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:11 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_printf_proc_precision(t_mod *conv)
{
	size_t	num;

	if (conv->precision)
	{
		if (ft_printf_stric(conv->conversion, "diouDOU", &num) == 1)
			ft_printf_proc_setchar_prec(conv, '0');
		else if (ft_printf_strchri(conv->conversion, 'x', &num) == 1)
			ft_printf_proc_setchar_prec(conv, '0');
		else if (ft_printf_strchri(conv->conversion, 'X', &num) == 1)
			ft_printf_proc_setchar_prec(conv, '0');
		else if (ft_printf_stric(conv->conversion, "sS", &num) == 1)
			ft_printf_proc_setchar_prec(conv, '\0');
		else
		{
			ft_printf_proc_setchar_prec(conv, '\0');
			ft_printf_strdel(&(conv->precision));
		}
	}
}
