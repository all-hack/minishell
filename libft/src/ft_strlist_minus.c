/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:29:17 by obelange          #+#    #+#             */
/*   Updated: 2017/01/23 18:29:21 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strlist_minus(char **strlist)
{
	char	**new_strlist;
	size_t	i;
	size_t	len;

	new_strlist = NULL;
	if (strlist)
	{
		i = 0;
		len = ft_strlist_len(strlist);
		new_strlist = ft_strlist_build(len - 1);
		while (i < len - 1)
		{
			new_strlist[i] = strlist[i];
			i++;
		}
		ft_strdel(&(strlist[i]));
		free(strlist);
	}
	return (new_strlist);
}
