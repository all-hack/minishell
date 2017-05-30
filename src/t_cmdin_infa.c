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





t_cmdin	*t_cmdin_build(void)
{
	t_cmdin	*cmdin;

	cmdin = NULL;

	if ((cmdin = (t_cmdin*)malloc(sizeof(t_cmdin))) == 0)
		msh_error("Error: failed to mallocate for cmdin\n");
	
	cmdin->cntrl[0] = ";";
	cmdin->cntrl[1] = "\n";
	cmdin->cntrl[2] = NULL;
	cmdin->words = NULL;
	cmdin->expand = t_hash_build(256);
	t_hash_add(cmdin->expand, "~", "HOME");

	return (cmdin);
}

void	t_cmdin_print(t_cmdin *cmdin)
{
	ft_strlist_print(cmdin->cntrl);
	ft_strlist_print(cmdin->words);
}

void	t_cmdin_del(t_cmdin **cmdin)
{
	if (cmdin && *cmdin)
	{
		ft_strlist_del(&(*cmdin)->words);
		t_hash_del(&(*cmdin)->expand);
		free(*cmdin);
		*cmdin = NULL;
	}
}















