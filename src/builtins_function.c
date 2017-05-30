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

void	builtin_echo(t_env *env, t_cmdin *cmdin)
{
	int		i;
	char	*str;
	int		flag;

	i = 0;
	str = NULL;
	flag = 0;
	if (ft_strlist_len(cmdin->words) > 1)
	{
		while (cmdin->words[++i])
			if (i == 1)
				str = ft_strdup(cmdin->words[i]);
			else
				str = ft_fstrmcat(ft_fstrmcat(str, " "), cmdin->words[i]);
		if (str[0] == '"' && str[ft_strlen(str) - 1] == '"')
			str = ft_strsub(str, 1, ft_strlen(str) - 2);
		ft_printf("%s\n", str);
	}
	else
		ft_printf("\n");
	
}

void	execute_cd(t_env *env, t_cmdin *cmdin)
{
	t_stat	stats;
	int		exists;
	int		executable;
	char	*buf;

	exists = access(cmdin->words[1], F_OK);
	executable = access(cmdin->words[1], X_OK);
	if (exists == 0)
	{
		stat(cmdin->words[1], &stats);
		if (S_ISDIR(stats.st_mode))
		{
			if (executable == 0)
			{
				t_env_add_variable(env, "OLDPWD", ft_strdup(t_hash_get(env->hash, "PWD")));
				chdir(cmdin->words[1]);			
				t_env_add_variable(env, "PWD", getcwd(NULL, 0));
			}	
			else
				ft_printf("%s: permission denied.\n", cmdin->words[0]);				
		}
		else
			ft_printf("%s: file is not a directory\n", cmdin->words[0]);
	}
	else
		ft_printf("%s: file not found.\n", cmdin->words[0]);		

}

void	builtin_cd(t_env *env, t_cmdin *cmdin)
{
	if (ft_strlist_len(cmdin->words) == 1)
		cmdin->words = ft_strlist_add(cmdin->words, t_hash_get(env->hash, "HOME"));
	if (ft_strlist_len(cmdin->words) > 2)
		ft_printf("%s: too many arguments.\n", cmdin->words[0]);
	else
	{
		execute_cd(env, cmdin);
	}
}















