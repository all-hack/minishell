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

void	ft_printf_reset_struct(t_mod **this)
{
	if (this && *this)
	{
		if ((*this)->flag)
			ft_printf_dfree_hack(&((*this)->flag));
		if ((*this)->prepend)
			ft_printf_dfree_hack(&((*this)->prepend));
		if ((*this)->length)
			ft_printf_dfree_hack(&((*this)->length));
		if ((*this)->conversion)
			ft_printf_dfree_hack(&((*this)->conversion));
		if ((*this)->substring)
			ft_printf_strdel(&((*this)->substring));
		if ((*this)->mfieldwidth)
			ft_printf_dfree_hack(&((*this)->mfieldwidth));
		if ((*this)->precision)
			ft_printf_dfree_hack(&((*this)->precision));
		(*this)->mfw = -1;
		(*this)->prec = -1;
		(*this)->cmfw = ' ';
		(*this)->cprec = '\0';
		(*this)->srt_seq = 0;
		(*this)->end_seq = 0;
	}
}
