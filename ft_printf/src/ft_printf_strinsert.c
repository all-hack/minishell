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

char	*ft_printf_strinsert(char *printit, char *substr,
													size_t strt, size_t end)
{
	char	*tmp;
	char	*str;

	tmp = ft_printf_fstrmcat(ft_printf_strsub(printit, 0, strt), substr);
	if (*tmp || *(printit + end))
		str = ft_printf_fstrmcat(tmp, (printit + end));
	else
		str = NULL;
	return (str);
}
