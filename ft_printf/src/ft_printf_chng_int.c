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

void	ft_printf_chng_int(t_mod *conv, int num)
{
	intmax_t	nam;

	if (num < 0)
	{
		nam = num;
		conv->substring = ft_printf_itoa_base(-nam, 10, 1);
	}
	else
		conv->substring = ft_printf_itoa_base(num, 10, 0);
}
