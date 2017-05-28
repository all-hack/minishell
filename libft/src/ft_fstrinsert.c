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

#include "libft.h"

void	ft_fstrinsert(char **printit, char *substr, size_t strt, size_t end)
{
	char	*tmp;
	char	*str;

	str = *printit;
	tmp = ft_fstrmcat(ft_strsub(str, 0, strt), substr);
	if (*tmp == '\0' && *(str + end) == '\0')
		*printit = NULL;
	else
		*printit = ft_fstrmcat(tmp, (str + end));
	ft_strdel(&str);
}
