/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:38:46 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 21:08:49 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extracts the value part of an environment variable definition.
 *
 * @param argv A string containing the environment variable definition in the
 * 	form 'name=value'.
 *
 * @return A newly allocated string containing the value of the variable, or
 * 	NULL if no value is defined.
 * The caller is responsible for freeing this string.
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
		return (NULL);
	ft_strlcpy(value, ptr, len);
	return (value);
}
