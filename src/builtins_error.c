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

void	builtin_no_permission(t_env *env, t_cmdin *cmdin)
{
	ft_printf("%s: permission denied.\n", cmdin->words[0]);
}

void	builtin_error(t_env *env, t_cmdin *cmdin)
{
	ft_printf("%s: command not found.\n", cmdin->words[0]);
}

void	builtin_nothing(t_env *env, t_cmdin *cmdin)
{
	return ;
}
