/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 21:48:18 by obelange          #+#    #+#             */
/*   Updated: 2016/10/20 21:48:21 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*env;

	NULL_GUARD((env = (t_list*)malloc(sizeof(t_list))));
	env->next = NULL;
	if (content)
	{
		if ((env->content = (void*)malloc(content_size)))
		{
			ft_memcpy(env->content, content, content_size);
			env->content_size = content_size;
		}
		else
		{
			free(env);
			return (NULL);
		}
	}
	else
	{
		env->content = 0;
		env->content_size = 0;
	}
	return (env);
}
