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

void	ft_printf_flag_minus(t_mod *conv)
{
	size_t	j;

	j = 0;
	if (conv->mfieldwidth)
	{
		if (ft_printf_stric(conv->conversion, "p", &j) == 0)
		{
			j = ft_printf_strlen(conv->mfieldwidth);
			ft_printf_fstrinsert(&(conv->substring),
				conv->mfieldwidth, conv->mfw, conv->mfw);
			ft_printf_fstrinsert(&(conv->substring), "", 0, j);
		}
	}
}
