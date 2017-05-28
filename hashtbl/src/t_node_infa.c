/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_infa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtbl.h"

t_node	*t_node_build(char *key, char *value)
{
	t_node	*node;

	node = NULL;
	if (key && value)
	{
		if ((node = (t_node*)malloc(sizeof(t_node))) == 0)
			hash_error("Error: failed to mallocate for t_node\n");
		node->key = key;
		node->value = value;
		node->nxt = NULL;
	}
	return (node);
}

void	t_node_del(t_node **node)
{
	t_node	*tmp;

	if (node)
	{
		if (*node)
		{
			if ((*node)->nxt)
				t_node_del(&((*node)->nxt));
			hash_strdel(&((*node)->key));
			hash_strdel(&((*node)->value));
			(*node)->nxt = NULL;
			free(*node);
			*node = NULL;
		}
	}
}
