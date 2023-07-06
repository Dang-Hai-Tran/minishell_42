/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:05:33 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:29:18 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if a string is a valid environment variable name.
 *
 * @param identifier The string to check.
 *
 * @return EXIT_SUCCESS if the string is a valid environment variable name.
 * @return EXIT_FAILURE otherwise.
 */
int	valid_env_name(char *identifier)
{
	char	*ptr;

	ptr = identifier;
	if (((*identifier < 'a' || *identifier > 'z') && (*identifier < 'A'
				|| *identifier > 'Z')) && *identifier != '_')
		return (EXIT_FAILURE);
	while (*ptr && *ptr != '=')
	{
		if (((*ptr < 'a' || *ptr > 'z') && (*ptr < 'A' || *ptr > 'Z'))
			&& (*ptr != '_') && ((*ptr < '0' || *ptr > '9')))
			return (EXIT_FAILURE);
		ptr++;
	}
	return (EXIT_SUCCESS);
}
