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

static void	norm_cheat00(t_mod *conv, size_t i, size_t j)
{
	if (ft_printf_strchri(conv->substring, 'x', &i))
	{
		ft_printf_fstrinsert(&(conv->substring),
			conv->mfieldwidth, i + 1, i + 1);
		ft_printf_fstrinsert(&(conv->substring), "", 0, j);
	}
	else
	{
		if (conv->num < 0)
		{
			ft_printf_strchri(conv->substring, '-', &i);
			ft_printf_fstrinsert(&(conv->substring),
				conv->mfieldwidth, i + 1, i + 1);
			ft_printf_fstrinsert(&(conv->substring), "", 0, j);
		}
		else
			ft_printf_fstrinsert(&(conv->substring), conv->mfieldwidth, 0, j);
	}
}

void		ft_printf_flag_0(t_mod *conv)
{
	size_t	i;
	size_t	j;

	if (!(conv->precision) && conv->mfieldwidth &&
		!(ft_printf_stric(conv->conversion, "sS", &i)) && conv->prec < 0)
	{
		i = 0;
		j = 0;
		j = ft_printf_strlen(conv->mfieldwidth);
		while ((conv->mfieldwidth)[i])
			(conv->mfieldwidth)[i++] = '0';
		norm_cheat00(conv, i, j);
	}
}
