/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fstrmcat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static	void	norm_cheat00(t_mod *conv, size_t index, size_t strt, char *s)
{
	if (ft_printf_strchri(conv->flag, '0', &strt) == 1)
	{
		if (conv->precision || ft_printf_stric(conv->conversion,
											"sSdDioOuUxXcC", &index) == 1)
		{
			if (ft_printf_stric(conv->conversion, "cCsS", &index) == 1 &&
							ft_printf_strchri(conv->flag, '-', &index) == 0)
				conv->cmfw = '0';
			if (ft_printf_strchri(conv->flag, '-', &index) == 1 ||
															conv->prec > 1)
				ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);
		}
	}
	if (ft_printf_strchri(conv->flag, '+', &index) == 1)
	{
		if (ft_printf_stric(conv->conversion, "dDi", &strt) == 0)
			ft_printf_fstrinsert(&(conv->flag), "", index, index + 1);
		if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)
			ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);
	}
	else if (ft_printf_strchri(conv->flag, ' ', &strt) == 1)
	{
		if (ft_printf_stric(conv->conversion, "dDi", &index) == 0)
			ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);
	}
}

void			ft_printf_proc_flags(t_mod *conv)
{
	size_t	index;
	size_t	strt;
	char	*s;

	if (conv->flag)
	{
		conv->flag = ft_printf_frmvdup(&(conv->flag),
											ft_printf_strlen(conv->flag));
		if (ft_printf_strchri(conv->flag, '#', &strt) == 1)
		{
			if (ft_printf_stric(conv->conversion, "cdDipSCscuU", &index) == 1)
				ft_printf_fstrinsert(&(conv->flag), "", strt, strt + 1);
		}
		norm_cheat00(conv, index, strt, s);
	}
}
