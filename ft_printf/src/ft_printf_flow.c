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

void	ft_printf_flow(char **seq, t_mod *conv, va_list args)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *seq;
	while (*g_printf_parse[i] != 0)
		(*g_printf_parse[i++])(seq, conv);
	i = 0;
	while (*g_printf_process[i] != 0)
		(*g_printf_process[i++])(conv);
	i = 0;
	while (*g_printf_apply[i] != 0)
		(*g_printf_apply[i++])(conv);
	free(tmp);
}
