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

static void	norm_cheat00(t_mod *conv, size_t i, size_t j, char *d)
{
	if (ft_printf_stric(conv->substring, d + 1, &j))
	{
		ft_printf_stric(conv->substring, d, &i);
		if (conv->mfieldwidth)
		{
			if (ft_printf_strlen(conv->mfieldwidth) < 2)
				ft_printf_fstrinsert(&(conv->substring),
					(conv->conversion[0] == 'x') ? "0x" : "0X", i, i);
			else
			{
				ft_printf_fstrinsert(&(conv->substring),
					(conv->conversion[0] == 'x') ? "0x" : "0X", i - 2, i);
				ft_printf_fstrinsert(&(conv->mfieldwidth),
					"", 0, 2);
			}
		}
		else
			ft_printf_fstrinsert(&(conv->substring),
				(conv->conversion[0] == 'x') ? "0x" : "0X", 0, 0);
	}
}

void		ft_printf_flag_hash(t_mod *conv)
{
	size_t	i;
	size_t	j;
	char	*d;

	d = "0123456789abcdef";
	if (ft_printf_strchri(conv->conversion, 'o', &i) == 1)
	{
		ft_printf_stric(conv->substring, "0", &i);
		ft_printf_stric(conv->substring, d + 1, &j);
		if ((i > j || !(conv->precision)) &&
			!(conv->mfieldwidth) && conv->num != 0)
			ft_printf_fstrinsert(&(conv->substring), "0", j, j);
		else if ((i > j || !(conv->precision)) &&
			conv->mfieldwidth && conv->num != 0)
		{
			ft_printf_fstrinsert(&(conv->substring), "0", j - 1, j);
			ft_printf_fstrinsert(&(conv->mfieldwidth), "", 0, 1);
		}
	}
	else if (ft_printf_stric(conv->conversion, "xX", &i) == 1)
		norm_cheat00(conv, i, j, d);
}
