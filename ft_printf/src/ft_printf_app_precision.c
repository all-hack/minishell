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

static void	norme_cheat00(t_mod *conv, intmax_t len,
						size_t i, char *tmp)
{
	intmax_t index;

	index = -1;
	if ((conv->prec - len) > 0)
	{
		while (++index < (conv->prec - len))
			conv->precision =
		ft_printf_fstrappend(conv->precision, conv->cprec);
		tmp = conv->substring;
		if (ft_printf_strchri(conv->substring, '-', &i) == 1)
			conv->substring =
		ft_printf_strinsert(conv->substring, conv->precision, i + 1, i + 1);
		else
			conv->substring =
		ft_printf_strinsert(conv->substring, conv->precision, 0, 0);
		ft_printf_strdel(&tmp);
	}
	if (conv->num == 0 && conv->prec == 0 && conv->mfieldwidth)
		conv->substring = ft_printf_strinsert(conv->substring, " ", 0, 1);
	else if (conv->num == 0 && conv->prec == 0 && !conv->mfieldwidth)
		conv->substring = ft_printf_strinsert(conv->substring, "", 0, 1);
}

void		ft_printf_app_precision(t_mod *conv)
{
	char		*tmp;
	size_t		i;
	intmax_t	index;
	intmax_t	len;

	if (conv->precision)
	{
		if (ft_printf_stric(conv->conversion, "diouDOUxX", &i) == 1)
		{
			len = ft_printf_strlen(conv->substring);
			if (ft_printf_strchri(conv->substring, '-', &i) == 1)
				len -= 1;
			ft_printf_strdel(&(conv->precision));
			norme_cheat00(conv, len, i, tmp);
		}
	}
}
