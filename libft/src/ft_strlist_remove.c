/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 22:37:48 by obelange          #+#    #+#             */
/*   Updated: 2017/01/24 22:37:49 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strlist_remove(char **strlist, char *str)
{
	char	**new_strlist;
	int		index;
	int		i;
	size_t	len;
	int		j;

	if (strlist)
	{
		i = -1;
		len = ft_strlist_len(strlist);
		index = ft_strlist_findindex(strlist, str);
		if (index >= 0)
		{
			new_strlist = ft_strlist_build(len - 1);
			j = 0;
			while (++i < len)
				if (i != index)
					new_strlist[j++] = strlist[i];
			ft_strdel(&strlist[index]);
			free(strlist);
			return (new_strlist);
		}
		return (strlist);
	}
	return (new_strlist);
}
