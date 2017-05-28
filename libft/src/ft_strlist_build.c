/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlist_build.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:28:41 by obelange          #+#    #+#             */
/*   Updated: 2017/01/23 18:28:43 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strlist_build(size_t size)
{
	char	**strlist;
	size_t	i;

	i = 0;
	if (!(strlist = (char **)malloc(sizeof(char*) * (size + 1))))
		write(2, "Error: failed to mallocate char **\n",
			ft_strlen("Error: failed to mallocate char **\n"));
	if (strlist)
		strlist[size] = NULL;
	return (strlist);
}
