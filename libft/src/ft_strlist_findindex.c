/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:43:15 by obelange          #+#    #+#             */
/*   Updated: 2017/01/24 22:43:16 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlist_findindex(char **strlist, char *str)
{
	size_t	j;

	j = 0;
	if (strlist && str)
	{
		while (strlist[j])
		{
			if (ft_strcmp(strlist[j], str) == 0)
				return (j);
			j++;
		}
	}
	return (-1);
}
