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

void	ft_printf_symdet_prec(char **seq, t_mod *conv)
{
	size_t	delim_index;
	size_t	i;
	char	*tmp;

	i = 0;
	delim_index = 0;
	tmp = NULL;
	if (ft_printf_1chr_nsym(*seq, g_precision_symbols, &tmp) == 1)
	{
		conv->precision = ft_printf_strdup(tmp + 1);
		ft_printf_strdel(&tmp);
		while (i < ft_printf_strlen(conv->precision) + 1)
		{
			(*seq)++;
			i++;
		}
	}
}
