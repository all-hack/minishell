/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:48:53 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 21:48:54 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;

	if (alst)
	{
		if (*alst)
		{
			while (*alst)
			{
				nxt = (*alst)->next;
				del((*alst)->content, (*alst)->content_size);
				free(*alst);
				*alst = nxt;
			}
			alst = 0;
		}
	}
}
