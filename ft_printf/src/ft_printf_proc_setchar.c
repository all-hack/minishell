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

void	ft_printf_proc_setchar_prec(t_mod *conv, char chr)
{
	size_t i;

	if (ft_printf_strchri(conv->precision, '*', &i) == 1)
		conv->prec = va_arg(conv->arg_list, int);
	else
		conv->prec = ft_printf_atoi(conv->precision);
	conv->cprec = chr;
}
