/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 14:47:59 by obelange          #+#    #+#             */
/*   Updated: 2016/09/30 14:47:59 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_space(char c)
{
	if (c != 32 && c != 9 && c != 10 && c != 11 && c != 12 && c != 13)
	{
		return (1);
	}
	else
		return (0);
}

static	char	*remove_leading_space(char const *str, char *dst)
{
	char	c;
	int		i;
	int		x;

	i = 0;
	x = -1;
	while (str[i])
	{
		c = str[i];
		if (x == -1)
		{
			if (is_space(c) == 1)
			{
				x = i;
			}
		}
		i++;
	}
	dst = (char*)&str[x];
	return (dst);
}

static	int		string_to_int(char *str, int size)
{
	int x;
	int j;
	int total;
	int power;

	j = 0;
	x = 0;
	power = 1;
	total = 0;
	while (size > 0)
	{
		size--;
		while (j < 10)
		{
			if (str[size] == ('0' + j))
				x = j;
			j++;
		}
		j = 0;
		total += (x * power);
		power *= 10;
	}
	return (total);
}

static	int		form_string(char const *str, int size)
{
	char	tmp[size + 1];
	int		i;

	i = 0;
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	i = string_to_int(tmp, i);
	return (i);
}

int				ft_atoi(char const *str)
{
	int		i;
	int		sign;
	char	*dst;
	char	c;

	dst = &c;
	sign = 1;
	str = remove_leading_space(str, dst);
	if (str[0] == '-')
	{
		sign = -1;
		str = &str[1];
		if (str[0] == '+')
			return (0);
	}
	if (str[0] == '+')
		str = &str[1];
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (i == 0)
		return (0);
	i = form_string(str, i);
	return (i * sign);
}
