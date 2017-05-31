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


t_cmdin	*t_cmdin_new_words(t_cmdin *cmdin, char *input)
{
	t_cmdin	*tmp;

	if (cmdin)
		tmp = cmdin;
	else
		tmp = t_cmdin_build();

	ft_strlist_del(&(tmp->words));
	tmp->words = msh_blanksplit(input, "\t ");
	return (tmp);
}


