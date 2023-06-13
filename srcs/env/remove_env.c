/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:06:59 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 17:07:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	remove_env(t_env *target)
{
	t_env	*tmp;

	tmp = g_manager.env;
	if (tmp == target)
		g_manager.env = tmp->next;
	else
	{
		while (tmp->next != target)
			tmp = tmp->next;
		tmp->next = target->next;
	}
	free(target->name);
	free(target->value);
	free(target);
}
