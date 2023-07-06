/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:54:55 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:01:58 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints an error message related to environment variables to the standard
 * error output, and sets the exit code of the shell to 1.
 *
 * @param cmd The command that caused the error.
 * @param argv The argument that caused the error.
 *
 * @return EXIT_FAILURE always.
 */
int	throw_error_env(char *cmd, char *argv)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd("`", STDERR_FILENO);
	ft_putstr_fd(argv, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier\n", STDERR_FILENO);
	g_manager.exit_code = 1;
	return (EXIT_FAILURE);
}
