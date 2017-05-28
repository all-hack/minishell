/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:04:40 by obelange          #+#    #+#             */
/*   Updated: 2017/01/24 22:04:42 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strlist_print(char **strlist)
{
	size_t	i;

	if (strlist)
	{
		i = 0;
		while (strlist[i])
		{
			ft_putstr(strlist[i++]);
			ft_putstr("\n");
		}
	}
}
