/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:38:46 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:01:10 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extract the value of an environment variable from a command-line argument 
 * that contains it.
 * @param argv A string representing the command-line argument that contains an 
 * environment variable.
 * @return a dynamically allocated string representing the value of the 
 * environment variable contained in the argv argument.
*/
char	*get_env_value(char *argv)
{
	char	*value;
	char	*ptr;
	int		len;

	ptr = ft_strchr(argv, '=');
	if (!ptr)
		return (NULL);
	ptr++;
	len = ft_strlen(ptr) + 1;
	value = (char *)ft_calloc(len, sizeof(char));
	if (!value)
		exit(EXIT_FAILURE);
	ft_strlcpy(value, ptr, len);
	return (value);
}
