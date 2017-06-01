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

t_env	*t_env_init(char **environ)
{
	t_env	*env;

	env = t_env_build();
	t_env_convert_environ_hash(env, environ);
	return (env);
}

void	t_env_prepare_builtins(t_env *env)
{
	if (env)
	{
		env->builtin_keys[0] = "exit";
		env->builtin_keys[1] = "env";
		env->builtin_keys[2] = "setenv";
		env->builtin_keys[3] = "unsetenv";
		env->builtin_keys[4] = "echo";
		env->builtin_keys[5] = "cd";
		env->builtin_keys[6] = NULL;
		env->builtin[0] = builtin_exit;
		env->builtin[1] = builtin_env;
		env->builtin[2] = builtin_setenv;
		env->builtin[3] = builtin_unsetenv;
		env->builtin[4] = builtin_echo;
		env->builtin[5] = builtin_cd;
		env->builtin[6] = NULL;
		env->builtin[7] = execute_command;
		env->builtin[8] = builtin_error;
		env->builtin[9] = builtin_nothing;
		env->builtin[10] = builtin_no_permission;
	}
}

t_env	*t_env_build(void)
{
	t_env	*env;

	env = NULL;
	if ((env = (t_env*)malloc(sizeof(t_env))) == 0)
		msh_error("Error: failed to mallocate for env\n");
	env->hash = t_hash_build(256);
	env->list = NULL;
	t_env_prepare_builtins(env);
	return (env);
}

void	t_env_del(t_env **env)
{
	if (env && *env)
	{
		t_hash_del(&(*env)->hash);
		ft_strlist_del(&(*env)->list);
		free(*env);
		*env = NULL;
	}
}
