/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:47:39 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 14:59:40 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Add a new environment variable to the linked list data structure that stores the environment variables for the shell program.
 * @param name A string representing the name of the environment variable to be added.
 * @param value A string representing the value of the environment variable to be added.
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
