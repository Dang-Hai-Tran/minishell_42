/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:33:53 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 14:59:40 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extract the name of an environment variable from a command-line argument that contains it.
 * @param argv A string representing the command-line argument that contains an environment variable.
 * @return A dynamically allocated string representing the name of the environment variable contained in the argv argument.
*/
char	*get_env_name(char *argv)
{
	char	*name;
	size_t	len;

	if (!ft_strchr(argv, '='))
		len = ft_strlen(argv) + 1;
	else
		len = ft_strchr(argv, '=') - argv + 1;
	name = (char *)ft_calloc(len, sizeof(char));
	if (!name)
		exit(EXIT_FAILURE);
	ft_strlcpy(name, argv, len);
	return (name);
}
