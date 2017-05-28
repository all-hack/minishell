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

static	void	norm_cheat00(t_mod *conv)
{
	conv->substring = ft_printf_strdup("(null)");
	conv->num = 0;
}

void			ft_printf_get_cap_s(t_mod *conv, va_list args)
{
	wchar_t		*tmp1;
	intmax_t	i;

	i = 0;
	if (!(conv->length))
	{
		tmp1 = va_arg(args, wchar_t*);
		if (!tmp1)
			norm_cheat00(conv);
		else if (conv->prec >= 0)
		{
			conv->substring = ft_printf_fstrmcat(conv->substring,
								ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
			while (tmp1[i++] && i < conv->prec)
				conv->substring = ft_printf_fstrmcat(conv->substring,
								ft_printf_chng_wchar_t(conv, tmp1[i], NULL));
		}
		else
			while (tmp1[i])
				conv->substring = ft_printf_fstrmcat(conv->substring,
								ft_printf_chng_wchar_t(conv, tmp1[i++], NULL));
	}
}
