/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:55:38 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:26:54 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Retrieves an environment variable from the shell's environment by its name.
 *
 * @param identifier The name of the variable to retrieve.
 *
 * @return A pointer to the environment variable, or NULL if no such variable exists.
 */
t_env	*get_env(char *identifier)
{
	t_env			*ptr;
	unsigned int	len;

	ptr = g_manager.env;
	len = ft_strlen(identifier);
	while (ptr)
	{
		if (ft_strlen(ptr->name) == len && ft_strncmp(identifier, ptr->name,
				len) == 0)
			return (ptr);
		ptr = ptr->next;
	}
	return (NULL);
}
