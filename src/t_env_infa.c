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
		env->builtin_keys[4] = NULL;
		env->builtin_keys[5] = NULL;
		env->builtin_keys[6] = NULL;

		env->builtin[0] = builtin_exit;
		env->builtin[1] = builtin_env;
		env->builtin[2] = builtin_setenv;
		env->builtin[3] = builtin_unsetenv;
		env->builtin[4] = NULL;
		env->builtin[5] = NULL;
		env->builtin[6] = NULL;
		env->builtin[7] = execute_command;
		env->builtin[8] = builtin_error;
		env->builtin[9] = builtin_nothing;
		env->builtin[10] = builtin_no_permission;
	}
}

// void	builtin_echo(t_env *env, t_cmdin *cmdin)
// {
// 	int	i;
// 	int	len;

// 	i = 0;
// 	len = ft_strlist_len(cmdin->words);
// 	while (cmdin->words[++i])
// 	{
// 		if (i == 0)
// 		{
// 			ft_printf("")
// 		}

// 	}
// }


void	execute_command(t_env *env, t_cmdin *cmdin)
{
	pid_t	child;
	int		stat_loc;
	int		exists;
	int		executable;

	exists = access(cmdin->words[0], F_OK);
	executable = access(cmdin->words[0], X_OK);
	if (exists == 0 && executable == 0)
	{
		child = fork();
		if (child == 0)
			execv(cmdin->words[0], cmdin->words);
		else if (child > 0)
			waitpid(child, &stat_loc, 0);
		else
			ft_printf("%s: fork failed.\n", cmdin->words[0]);
	}
	else if (exists < 0)
		ft_printf("%s: command not found.\n", cmdin->words[0]);
	else if (executable < 0)
		ft_printf("%s: permission denied.\n", cmdin->words[0]);
}

void	builtin_no_permission(t_env *env, t_cmdin *cmdin)
{
	ft_printf("%s: do not have proper permissions to execute.\n", cmdin->words[0]);
}

void	builtin_error(t_env *env, t_cmdin *cmdin)
{
	ft_printf("%s: command not found.\n", cmdin->words[0]);
}

void	builtin_nothing(t_env *env, t_cmdin *cmdin)
{
	return ;
}

void	builtin_unsetenv(t_env *env, t_cmdin *cmdin)
{
	// ft_printf("checkle\n");
	if (ft_strlist_len(cmdin->words) == 1)
	{
		ft_strlist_print(env->list);
	}
	else if (ft_strlist_len(cmdin->words) == 2)
	{
		// ft_printf("cuckle\n");
		t_env_remove_variable(env, cmdin->words[1]);
	}
	else
		ft_printf("unsetenv: Too many arguments\n");	
}

void	builtin_setenv(t_env *env, t_cmdin *cmdin)
{
	if (ft_strlist_len(cmdin->words) == 1)
		ft_strlist_print(env->list);
	else if (ft_strlist_len(cmdin->words) == 2)
		ft_printf("setenv: Must have either 0 or 2 arguments\n");
	else if (ft_strlist_len(cmdin->words) == 3)
		t_env_add_variable(env, cmdin->words[1], cmdin->words[2]);
	else
		ft_printf("setenv: Too many arguments\n");
}

void	builtin_env(t_env *env, t_cmdin *cmdin)
{
	ft_strlist_print(env->list);
}

void	builtin_exit(t_env *env, t_cmdin *cmdin)
{
	if (ft_strlist_len(cmdin->words) == 1)
	{
		t_env_del(&env);
		t_cmdin_del(&cmdin);
		ft_printf("exiting...\n");
		exit(1);
	}
	else
		ft_printf("exit: Expression Syntax.\n");
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















