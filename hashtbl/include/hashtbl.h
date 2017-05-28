/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 09:43:04 by obelange          #+#    #+#             */
/*   Updated: 2016/10/27 09:43:07 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTBL_H
# define HASHTBL_H
# define HASHTBL_SIZE 256
# define NULLGUARD(INPUT) if ((INPUT) == NULL) return (-1)
# define NULL_GUARD(INPUT) if ((INPUT) == NULL) return (NULL)
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_node
{
	struct s_node	*nxt;
	char			*key;
	char			*value;
}				t_node;

typedef	struct	s_hash
{
	t_node	**map;
	int		size;
}				t_hash;

void			hash_error(char *message);

int				hash_strlen(char *str);
void			hash_bzero(void *s, size_t n);
void			hash_strdel(char **as);
char			*hash_strdup(char *s1);
char			*hash_strnew(size_t size);
int				hash_strcmp(const char *s1, const char *s2);

t_hash			*t_hash_build(int bucket_size);
unsigned long	t_hash_hashing(unsigned char *key, int bucket_size);
void			t_hash_del(t_hash **hash);
void			t_hash_print(t_hash *hash);
int				t_hash_add(t_hash *hash, char *key, char *value);
char			*t_hash_get(t_hash *hash, char *key);
int				t_hash_update(t_hash *hash, char *key, char *value);
int				t_hash_remove(t_hash *hash, char *key);

void			t_node_print_chain(t_node *node);
void			t_node_print(t_node *node);
void			t_node_del(t_node **node);
t_node			*t_node_build(char *key, char *value);
#endif
