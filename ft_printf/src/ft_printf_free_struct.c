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

static	void	norm_cheat00(t_mod *this)
{
	this->mfw = -1;
	this->cmfw = ' ';
	this->prec = -1;
	this->cprec = '\0';
	this->skips = 0;
	this->srt_seq = 0;
	this->end_seq = 0;
}

void			ft_printf_free_struct(t_mod **this)
{
	if (this)
	{
		if (*this)
		{
			if ((*this)->flag)
				free((*this)->flag);
			if ((*this)->prepend)
				free((*this)->prepend);
			if ((*this)->length)
				free((*this)->length);
			if ((*this)->conversion)
				free((*this)->conversion);
			if ((*this)->substring)
				free((*this)->substring);
			if ((*this)->mfieldwidth)
				free((*this)->mfieldwidth);
			if ((*this)->precision)
				free((*this)->precision);
			norm_cheat00(*this);
			va_end((*this)->arg_list);
			free((*this));
		}
	}
}
