/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:27:03 by obelange          #+#    #+#             */
/*   Updated: 2016/10/19 16:27:05 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if ((str = (void*)malloc(sizeof(char) * (size))))
	{
		while (size > 0)
			((char*)str)[size--] = 0;
		((char*)str)[size] = 0;
		return (str);
	}
	else
		return (0);
}
