/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:06:59 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:27:13 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Removes an environment variable from the shell's environment.
 *
 * @param target A pointer to the environment variable to remove.
 */
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
