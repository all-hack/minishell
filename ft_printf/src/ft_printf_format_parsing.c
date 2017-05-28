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

void	ft_printf_format_parsing(char const *format, t_mod *conv, va_list args)
{
	char	*fsub;
	char	*rem;

	if (conv)
	{
		ft_printf_stric(format, g_sequence_symbols, &(conv->srt_seq));
		ft_printf_stric(&((format)[conv->srt_seq + 1]),
			g_conversion_symbols, &(conv->end_seq));
		fsub = ft_printf_strsub(format, conv->srt_seq + 1,
			conv->end_seq + 1);
		conv->end_seq += conv->srt_seq + 1;
		ft_printf_flow(&fsub, conv, args);
	}
}
