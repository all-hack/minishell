/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_hash_infa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtbl.h"

t_hash			*t_hash_build(int bucket_size)
{
	t_hash			*hash;
	static	t_node	*map[HASHTBL_SIZE];
	int				i;

	i = -1;
	hash = NULL;
	if ((hash = (t_hash*)malloc(sizeof(t_hash))) == 0)
		hash_error("Error: failed to mallocate for t_hash\n");
	hash->map = map;
	hash->size = HASHTBL_SIZE;
	return (hash);
}

unsigned long	t_hash_hashing(unsigned char *key, int bucket_size)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *key++))
		hash = ((hash << 5) + hash) + c;
	return (hash % bucket_size);
}

void			t_hash_del(t_hash **hash)
{
	int i;

	i = -1;
	if (hash)
	{
		if (*hash)
		{
			while (++i < (*hash)->size)
				t_node_del(&(((*hash)->map)[i]));
			free(*hash);
			*hash = NULL;
		}
	}
}
