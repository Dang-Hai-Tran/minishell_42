/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 12:49:13 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Implements the 'env' shell command, which prints the shell's environment
 * variables to standard output. Each variable is printed in the form
 * of 'name=value'.
 *
 * @param argv An array of strings, representing the 'env' command and its 
 * 	arguments. The first element is the command itself ('env'), and the rest
 * 	are the arguments.
 *
 * @return EXIT_SUCCESS after printing the environment variables.
 * @return An error code if the 'env' command is followed by an argument, which
 * is not supported.
 */
int	env_command(char **argv)
{
	t_env	*current_env;

	current_env = g_manager.env;
	if (*(argv + 1))
		return (throw_error_usage("env", *(argv + 1)));
	while (current_env)
	{
		if (current_env->value)
		{
			ft_putstr_fd(current_env->name, STDOUT_FILENO);
			write(STDOUT_FILENO, "=", 1);
			ft_putstr_fd(current_env->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\n", 1);
		}
		current_env = current_env->next;
	}
	return (EXIT_SUCCESS);
}
