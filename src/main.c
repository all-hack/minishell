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







int	classify_cmd(t_env *env, t_cmdin *cmdin)
{
	int	i;

	i = -1;
	if (env && cmdin && cmdin->words)
	{
		if (ft_strcmp(cmdin->words[0], "") != 0)
		{
			while (env->builtin_keys[++i])
			{
				if (ft_strcmp(env->builtin_keys[i], cmdin->words[0]) == 0)
					return (i);
			}
		}
		else
			return (DO_NOTHING);
	}
	return (NOT_FOUND);
}





int	main(int argc, char **argv, char** envp)
{
	// while (1){
	
	t_env	*env;
	char	*line;
	t_cmdin	*cmdin;

	env = t_env_init(envp);
	cmdin = NULL;
	while (1)
	{
		ft_printf("> ");
		get_next_line(0, &line);
		// ft_printf("this is the line: %s\n", line);
		cmdin = t_cmdin_new_words(NULL, line);
		ft_strdel(&line);
		env->builtin[classify_cmd(env, cmdin)](env, cmdin);
	}		



	// t_cmdin_print(cmdin);
	

	// ft_strlist_print(envp);















	t_env_del(&env);
	// sleep(100);
	// }
}






























