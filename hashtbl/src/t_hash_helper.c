/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hash_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtbl.h"

void	hash_error(char *message)
{
	write(1, message, hash_strlen(message));
	exit(1);
}

int		t_hash_add(t_hash *hash, char *key, char *value)
{
	unsigned long	index;
	t_node			*node;

	if (!hash || !key || !value)
		return (0);
	index = t_hash_hashing((unsigned char*)key, hash->size);
	node = hash->map[index];
	if (node)
	{
		while (node->nxt)
			node = node->nxt;
		node->nxt = t_node_build(key, value);
	}
	else
		hash->map[index] = t_node_build(key, value);
	return (1);
}

int		t_hash_remove(t_hash *hash, char *key)
{
	unsigned long	index;
	t_node			*node;
	t_node			*tmp;

	if (!hash || !key)
		return (0);
	index = t_hash_hashing((unsigned char*)key, hash->size);
	if (hash->map[index] == NULL)
		return (1);
	node = hash->map[index];
	tmp = NULL;
	while (node)
	{
		if (hash_strcmp(key, node->key) == 0)
		{
			if (tmp)
				tmp->nxt = node->nxt;
			else
				hash->map[index] = node->nxt;
			t_node_del(&node);
			return (1);
		}
		else
		{
			tmp = node;
			node = node->nxt;
		}
	}
	return (0);
}

char	*t_hash_get(t_hash *hash, char *key)
{
	unsigned long	index;
	t_node			*node;

	if (!hash || !key)
		return (NULL);
	index = t_hash_hashing((unsigned char*)key, hash->size);
	if (hash->map[index] == NULL)
		return (NULL);
	node = hash->map[index];
	while (node)
	{
		if (hash_strcmp(key, node->key) == 0)
			return (node->value);
		else
			node = node->nxt;
	}
	return (NULL);
}

int		t_hash_update(t_hash *hash, char *key, char *value)
{
	unsigned long	index;
	t_node			*node;

	if (!hash || !key)
		return (0);
	index = t_hash_hashing((unsigned char*)key, hash->size);
	if (hash->map[index] == NULL)
		return (t_hash_add(hash, key, value));
	node = hash->map[index];
	while (node)
	{
		if (hash_strcmp(key, node->key) == 0)
		{
			free(node->value);
			node->value = value;
			return (1);
		}
		else if (!node)
			return (t_hash_add(hash, key, value));
		else
			node = node->nxt;
	}
	return (0);
}
