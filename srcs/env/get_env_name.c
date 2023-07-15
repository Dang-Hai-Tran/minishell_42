/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:33:53 by datran            #+#    #+#             */
/*   Updated: 2023/07/15 12:47:44 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extracts the name part of an environment variable definition.
 *
 * @param argv A string containing the environment variable definition in the
 * 	form 'name=value'.
 *
 * @return A newly allocated string containing the name of the variable.
 * The caller is responsible for freeing this string.
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
