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

#include "minishell.h"


void	t_env_convert_environ_hash(t_env *env, char **environ)
{
	int		i;
	char	**tmp;

	if (env && environ)
	{
		i = -1;
		while(environ[++i])
		{			
			tmp = ft_strsplit(environ[i], '=');
			if (tmp)
			{
				t_hash_add(env->hash, tmp[0], tmp[1]);			
				env->list = ft_strlist_add(env->list, environ[i]);
				free(tmp);
			}
		}
	}
}

void	t_env_add_variable(t_env *env, char *key, char *value)
{
	char	*tmp;

	tmp = NULL;
	if (t_hash_get(env->hash, key))
	{
		tmp = ft_fstrmcat(ft_strmcat(key, "="), t_hash_get(env->hash, key));
		env->list = ft_strlist_remove(env->list, tmp);		
		ft_strdel(&tmp);
		t_hash_update(env->hash, key, value);
		if (value)
			env->list = ft_strlist_add(env->list, 
				ft_fstrmcat(ft_strmcat(key, "="), value)
			);		
		else
			env->list = ft_strlist_add(env->list, ft_strmcat(key, "="));
	}
	else
	{
		if (value)
			env->list = ft_strlist_add(env->list, 
				ft_fstrmcat(ft_strmcat(key, "="), value)
			);
		else
			env->list = ft_strlist_add(env->list, ft_strmcat(key, "="));
		t_hash_add(env->hash, key, value);
	}
}

void	t_env_remove_variable(t_env *env, char *key)
{
	char	*tmp;

	tmp = NULL;
	if (t_hash_get(env->hash, key))
	{
		tmp = ft_fstrmcat(ft_strmcat(key, "="), t_hash_get(env->hash, key));
		env->list = ft_strlist_remove(env->list, tmp);		
		ft_strdel(&tmp);
		t_hash_remove(env->hash, key);
	}
}
