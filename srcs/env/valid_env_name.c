/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:33 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 13:10:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if a string is a valid environment variable name.
 *
 * @param identifier The string to check.
 *
 * @return true if the string is a valid environment variable name.
 * @return false otherwise.
 */
int	valid_env_name(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	if (((*identifier < 'a' || *identifier > 'z') && (*identifier < 'A'
				|| *identifier > 'Z')) && *identifier != '_')
		return (false);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr < '0' || *ptr > '9')))
			return (false);
		ptr++;
	}
	return (true);
}
