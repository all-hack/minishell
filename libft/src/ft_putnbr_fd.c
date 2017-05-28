/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 14:55:54 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 14:55:55 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ut_abs_fd(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

void		ft_putnbr_fd(int nb, int fd)
{
	int		i;
	char	c;

	if (nb == -2147483648)
		i = 1000000000;
	else
		i = 1;
	while (ut_abs_fd((nb / i)) >= 10)
		i *= 10;
	if (nb < 0)
		write(fd, "-", 1);
	while (i > 0)
	{
		c = ut_abs_fd(((nb / i) % 10)) + '0';
		write(fd, &c, 1);
		i /= 10;
	}
}
