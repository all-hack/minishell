/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:06:02 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:06:06 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define NULLGUARD(INPUT) if ((INPUT) == NULL) return (-1)
# define FGUARD(INPUT) if ((INPUT) == -1) return (-1)
# define FILEGUARD(INPUT) if ((INPUT) == -1) return (-1)
# define DO_NOTHING 9
# define NOT_FOUND 8
# define NO_PERMISSION 10
# define EXECUTE 7
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <libftprintf.h>
# include "libft.h"
# include "hashtbl.h"


typedef	struct	s_cmdin
{	
	char		*cntrl[3];
	t_hash		*expand;
	char		**words;
}				t_cmdin;

typedef	struct	s_env
{	
	t_hash		*hash;
	char		**list;
	char		*builtin_keys[7];
	void 		(*builtin[11])(struct s_env *env, t_cmdin *cmdin);
}				t_env;



void		msh_error(char *message);
int			classify_cmd(t_env *env, t_cmdin *cmdin);



t_cmdin		*t_cmdin_build(void);
void		t_cmdin_del(t_cmdin **cmdin);
void		t_cmdin_print(t_cmdin *cmdin);
t_cmdin		*t_cmdin_new_words(t_cmdin *cmdin, char *input);

t_env		*t_env_build(void);
void		t_env_del(t_env **env);
void		t_env_convert_environ_hash(t_env *env, char **environ);
t_env		*t_env_init(char **environ);
void		t_env_add_variable(t_env *env, char *key, char *value);
void		t_env_remove_variable(t_env *env, char *key);

void		builtin_error(t_env *env, t_cmdin *cmdin);
void		builtin_exit(t_env *env, t_cmdin *cmdin);
void		builtin_nothing(t_env *env, t_cmdin *cmdin);
void		builtin_env(t_env *env, t_cmdin *cmdin);
void		builtin_setenv(t_env *env, t_cmdin *cmdin);
void		builtin_unsetenv(t_env *env, t_cmdin *cmdin);
void		builtin_no_permission(t_env *env, t_cmdin *cmdin);
void		execute_command(t_env *env, t_cmdin *cmdin);

#endif
