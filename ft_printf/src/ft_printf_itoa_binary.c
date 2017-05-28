/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_itoa_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 20:03:14 by obelange          #+#    #+#             */
/*   Updated: 2016/11/27 20:03:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char		*reverse_string(char *str)
{
	size_t	k;
	size_t	i;
	char	c;

	i = 0;
	k = ft_printf_strlen(str) - 1;
	while (i < k)
	{
		c = str[i];
		str[i++] = str[k];
		str[k--] = c;
	}
	return (str);
}

char			*ft_printf_itoa_binary(uintmax_t num, int size)
{
	char	*key;
	char	*str;
	size_t	i;
	int		str_size;

	key = "01";
	str_size = (size * 8) + (size * 2) - 1;
	str = ft_printf_strnew(str_size);
	i = 0;
	while (i < str_size)
		if ((i + 1) % 5 == 0 && i != 0)
			str[i++] = ' ';
		else
			str[i++] = '0';
	i = 0;
	while (num > 0 && str[i])
		if ((i + 1) % 5 == 0 && i != 0)
			str[i++] = ' ';
		else
		{
			str[i++] = key[num % 2];
			num /= 2;
		}
	return (reverse_string(str));
}
