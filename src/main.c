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

extern char **g_environ;

int		search_path(t_env *env, t_cmdin *cmdin, int exists, int executable)
{
	char	**paths;
	int		i;
	int		len;

	if (t_hash_get(env->hash, "PATH"))
	{
		paths = ft_strsplit(t_hash_get(env->hash, "PATH"), ':');
		i = -1;
		len = ft_strlist_len(paths);
		while (paths[++i])
		{
			paths[i] = ft_fstrmcat(ft_fstrmcat(paths[i], "/"), cmdin->words[0]);
			exists += access(paths[i], F_OK);
			if (exists == i * -1)
			{
				ft_strdel(&(cmdin->words[0]));
				cmdin->words[0] = ft_strdup(paths[i]);
				ft_strlist_del(&paths);
				return (EXECUTE);
			}
		}
		ft_strlist_del(&paths);
	}
	return (NOT_FOUND);
}

int		classify_cmd(t_env *env, t_cmdin *cmdin)
{
	int	i;

	i = -1;
	if (env && cmdin && cmdin->words)
	{
		if (ft_strcmp(cmdin->words[0], "") != 0)
		{
			if (ft_strchr(cmdin->words[0], '/') != NULL)
				return (EXECUTE);
			while (env->builtin_keys[++i])
			{
				if (ft_strcmp(env->builtin_keys[i], cmdin->words[0]) == 0)
					return (i);
			}
			return (search_path(env, cmdin, 0, 0));
		}
		else
			return (DO_NOTHING);
	}
	return (NOT_FOUND);
}

void	expand_words(t_env *env, t_cmdin *c, char *tmp)
{
	int		i;
	size_t	index;

	i = 0;
	if (ft_strlist_len(c->words) == 2)
		if (ft_strcmp(c->words[0], "cd") == 0
			&& ft_strcmp(c->words[1], "-") == 0)
		{
			tmp = c->words[1];
			c->words[1] = ft_strdup(t_hash_get(env->hash, "OLDPWD"));
			ft_strdel(&tmp);
		}
	while (c->words[++i])
		if (c->words[i][0] == '$')
		{
			if (t_hash_get(env->hash, c->words[i] + 1))
			{
				tmp = c->words[i];
				c->words[i] = ft_strdup(t_hash_get(env->hash, c->words[i] + 1));
				ft_strdel(&tmp);
			}
		}
		else if (ft_strchri(c->words[i], '~', &index))
			ft_fstrinsert(&(c->words[i]),
				t_hash_get(env->hash, "HOME"), index, 1);
}

int		main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*line;
	t_cmdin	*cmdin;

	env = t_env_init(envp);
	cmdin = NULL;
	line = NULL;
	while (1)
	{
		g_environ = env->list;
		ft_printf("> ");
		get_next_line(0, &line);
		cmdin = t_cmdin_new_words(cmdin, line);
		ft_strdel(&line);
		expand_words(env, cmdin, NULL);
		env->builtin[classify_cmd(env, cmdin)](env, cmdin);
	}
}
