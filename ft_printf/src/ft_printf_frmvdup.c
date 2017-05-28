/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:08:09 by obelange          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:11 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char static		*copy_ignore_0(char *dst, char **src, size_t len, size_t size)
{
	size_t	i;
	char	*tmp;

	tmp = *src;
	i = 0;
	while (i < len)
	{
		while (**src)
		{
			dst[i] = **src;
			(*src)++;
			i++;
		}
		(*src)++;
	}
	ft_printf_strdel(&tmp);
	return (dst);
}

static	void	norm_cheat00(size_t *len, size_t size, size_t *x, size_t *i)
{
	*x = 0;
	*len = size - 1;
	*i = 0;
}

static	void	norm_cheat01(char *str, size_t *x, char c, size_t *i)
{
	if (str[*i] == c)
	{
		*x += 1;
		str[*i] = '\0';
	}
	*i += 1;
}

char			*ft_printf_frmvdup(char **str, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	x;
	char	c;

	norm_cheat00(&len, size, &x, &i);
	while (len > 0)
	{
		c = **str;
		if (**str)
		{
			(*str)++;
			while (i < len)
				norm_cheat01(*str, &x, c, &i);
			i = 0;
		}
		else
			(*str)++;
		len--;
	}
	*str = (*str) - (size - 1);
	return (copy_ignore_0(ft_printf_strnew(size - x), str, size - x, size));
}
