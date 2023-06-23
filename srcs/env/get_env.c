/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:55:38 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:01:46 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Retrieve an environment variable from the linked list data structure that 
 * stores the environment variables for the shell program.
 * @param identifier A string representing the name of the environment variable 
 * to be retrieved.
 * @return A pointer to the node in the linked list that contains the 
 * environment variable with the specified identifier. If no such environment 
 * variable is found, the function returns NULL.
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
