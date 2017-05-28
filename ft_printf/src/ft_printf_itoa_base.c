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

static size_t	count_digits(uintmax_t num, int base, int extra)
{
	size_t x;

	x = extra;
	while (num > 0)
	{
		num /= base;
		x++;
	}
	if (num == 0)
		x++;
	return (x);
}

char			*ft_printf_itoa_base(uintmax_t num, int base, int neg)
{
	char	*key;
	char	*str;
	size_t	i;

	key = "0123456789abcdef";
	if (neg == 1)
		str = ft_printf_strnew(count_digits(num, base, 1));
	else
		str = ft_printf_strnew(count_digits(num, base, 0));
	if (num == 0)
		str[0] = '0';
	i = 0;
	while (num > 0)
	{
		str[i++] = key[num % base];
		num /= base;
	}
	if (neg == 1)
		str[i] = '-';
	return (reverse_string(str));
}
