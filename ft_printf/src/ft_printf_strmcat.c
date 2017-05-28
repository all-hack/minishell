/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:58 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:58 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_printf_strmcat(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*nstr;
	size_t	i;

	if (s1)
		s1_len = ft_printf_strlen(s1);
	else
		s1_len = 0;
	if (s2)
		s2_len = ft_printf_strlen(s2);
	else
		s2_len = 0;
	nstr = ft_printf_strnew((s1_len + s2_len + 1));
	ft_printf_strncpy(nstr, s1, s1_len);
	ft_printf_strcat(nstr, s2);
	return (nstr);
}
