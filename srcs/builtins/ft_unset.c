/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:46 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:58:36 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Implements the 'unset' shell command, which removes environment variables.
 * The function supports multiple arguments, which are the names of the
 * variables to remove.
 *
 * @param arguments An array of strings, representing the 'unset' comman
 * 	and its arguments. The first element is the command itself ('unset')
 * 	and the rest are the arguments.
 *
 * @return EXIT_SUCCESS if all arguments are processed successfully.
 * @return An error code if any of the arguments is invalid.
 */
int	perform_unset(char **arguments)
{
	t_env	*target;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (!*(arguments + 1))
		return (exit_code);
	arguments++;
	while (*arguments)
	{
		if (check_option(*arguments) == EXIT_FAILURE)
			exit_code = throw_error_usage("unset", *arguments) + 1;
		else if (ft_strchr(*arguments, '='))
			exit_code = throw_error_env("unset", *arguments);
		else if (valid_env_name(*arguments) == EXIT_FAILURE)
			exit_code = throw_error_env("unset", *arguments);
		else
		{
			target = get_env(*arguments);
			if (target)
				remove_env(target);
		}
		arguments++;
	}
	return (exit_code);
}
