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

void	builtin_unsetenv(t_env *env, t_cmdin *cmdin)
{
	if (ft_strlist_len(cmdin->words) == 1)
	{
		ft_strlist_print(env->list);
	}
	else if (ft_strlist_len(cmdin->words) == 2)
	{
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
