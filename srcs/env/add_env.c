/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:47:39 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:25:34 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Adds an environment variable to the shell's environment.
 *
 * @param name The name of the variable to add.
 * @param value The value of the variable to add.
 */
void	add_env(char *name, char *value)
{
	t_env	*ptr;
	t_env	*new;

	ptr = g_manager.env;
	new = (t_env *)ft_calloc(1, sizeof(t_env));
	if (!new)
		exit(EXIT_FAILURE);
	new->name = name;
	new->value = value;
	new->next = NULL;
	if (!g_manager.env)
	{
		g_manager.env = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
