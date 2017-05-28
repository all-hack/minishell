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

t_mod	*ft_printf_init_struct(void)
{
	t_mod	*here;

	FT_PRINTF_NULLGUARD(here = (t_mod*)malloc(sizeof(t_mod)));
	here->cmfw = ' ';
	here->cprec = '\0';
	here->mfw = -1;
	here->prec = -1;
	here->skips = 0;
	here->srt_seq = 0;
	here->end_seq = 0;
	here->flag = NULL;
	here->prepend = NULL;
	here->length = NULL;
	here->conversion = NULL;
	here->substring = NULL;
	here->mfieldwidth = NULL;
	here->precision = NULL;
	return (here);
}
