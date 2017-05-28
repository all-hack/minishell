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

void	ft_printf_app_mfieldwidth(t_mod *conv)
{
	char		*tmp;
	intmax_t	index;
	intmax_t	len;
	size_t		i;

	if (conv->mfieldwidth)
	{
		if (ft_printf_stric(conv->conversion, "sSdDioOuUxXcCb%", &i) == 1)
		{
			len = ft_printf_strlen(conv->substring);
			index = -1;
			ft_printf_strdel(&(conv->mfieldwidth));
			if ((conv->mfw - len) > 0)
			{
				while (++index < (conv->mfw - len))
					conv->mfieldwidth =
					ft_printf_fstrappend(conv->mfieldwidth, conv->cmfw);
				tmp = conv->substring;
				conv->substring =
				ft_printf_strinsert(conv->substring, conv->mfieldwidth, 0, 0);
				ft_printf_strdel(&tmp);
			}
		}
	}
}
