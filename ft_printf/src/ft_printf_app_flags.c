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

void	ft_printf_app_flags(t_mod *conv)
{
	int		i;
	char	*flags;
	size_t	j;

	if (conv->prec != 0 || conv->num != 0)
	{
		if (conv->flag && !ft_printf_stric(conv->conversion, "p", &j))
		{
			i = 0;
			flags = "#0- +";
			while (*g_printf_flags[i] != 0)
			{
				if (ft_printf_strchri(conv->flag, flags[i], &j))
					(*g_printf_flags[i])(conv);
				i++;
			}
		}
	}
}
