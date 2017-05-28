/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:43:58 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 14:43:59 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ut_abs(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void		ft_putnbr(int nb)
{
	int		i;
	char	c;

	if (nb == -2147483648)
		i = 1000000000;
	else
		i = 1;
	while (ut_abs((nb / i)) >= 10)
		i *= 10;
	if (nb < 0)
		write(1, "-", 1);
	while (i > 0)
	{
		c = ut_abs(((nb / i) % 10)) + '0';
		write(1, &c, 1);
		i /= 10;
	}
}
