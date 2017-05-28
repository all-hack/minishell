/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 12:19:06 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 12:19:08 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_t;
	size_t	i;
	char	*nstr;

	if (s1 && s2)
	{
		i = 0;
		len_t = ft_strlen(s1) + ft_strlen(s2);
		if ((nstr = ft_strnew(len_t)))
		{
			while (*s1)
			{
				nstr[i] = *s1++;
				i++;
			}
			while (*s2)
			{
				nstr[i] = *s2++;
				i++;
			}
			return (nstr);
		}
		return (0);
	}
	return (NULL);
}
