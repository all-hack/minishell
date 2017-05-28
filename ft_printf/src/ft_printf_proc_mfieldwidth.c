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

void	ft_printf_proc_mfieldwidth(t_mod *conv)
{
	size_t i;

	if (conv->mfieldwidth)
	{
		if (ft_printf_strchri(conv->mfieldwidth, '*', &i) == 1)
			conv->mfw = va_arg(conv->arg_list, int);
		else
			conv->mfw = ft_printf_atoi(conv->mfieldwidth);
		conv->cmfw = ' ';
	}
}
