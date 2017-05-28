/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:28:59 by obelange          #+#    #+#             */
/*   Updated: 2017/01/23 18:29:02 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strlist_add(char **strlist, char *str)
{
	char	**new_strlist;
	size_t	i;

	if (strlist && str)
	{
		i = 0;
		new_strlist = ft_strlist_build(ft_strlist_len(strlist) + 1);
		while (strlist[i])
		{
			new_strlist[i] = strlist[i];
			i++;
		}
		new_strlist[i] = ft_strdup(str);
		free(strlist);
		return (new_strlist);
	}
	else if (str)
	{
		new_strlist = ft_strlist_build(1);
		new_strlist[0] = ft_strdup(str);
		return (new_strlist);
	}
	return (NULL);
}
