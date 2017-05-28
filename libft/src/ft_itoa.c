/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 18:24:33 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 18:24:35 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ut_abs_itoa(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static	char	*memalloc_itoa(int *size, char c, int nb)
{
	char	*str;
	int		i;

	i = 0;
	if (nb == -2147483648)
		*size = 11;
	else if (c == '-')
		(*size)++;
	if ((str = (char*)malloc(sizeof(char) * (*size + 1))))
	{
		str[(*size)] = '\0';
		while (i < *size)
		{
			str[i] = c;
			i++;
		}
		*size = 0;
		if (str[0] == '-')
			*size = 1;
		return (str);
	}
	else
		return (0);
}

char			*ft_itoa(int nb)
{
	int		i;
	int		k;
	char	*str;
	char	c;

	k = 1;
	if (nb == -2147483648)
		i = 1000000000;
	else
		i = 1;
	while (ut_abs_itoa((nb / i)) >= 10)
	{
		i *= 10;
		k++;
		c = 'x';
	}
	if (nb < 0)
		c = '-';
	NULL_GUARD((str = memalloc_itoa(&k, c, nb)));
	while (i > 0)
	{
		str[k++] = ut_abs_itoa(((nb / i) % 10)) + '0';
		i /= 10;
	}
	return (str);
}
