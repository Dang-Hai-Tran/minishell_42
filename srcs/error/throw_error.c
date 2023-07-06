/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:05:36 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:33:49 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints an error message to the standard error output,
 * and sets the exit code of the shell to 1.
 *
 * @param cmd The command that caused the error.
 * @param argv The argument that caused the error.
 * @param err The error message.
 *
 * @return EXIT_FAILURE always.
 */
int	throw_error(char *cmd, char *argv, char *err)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	if (argv)
	{
		ft_putstr_fd(argv, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
	}
	ft_putstr_fd(err, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_manager.exit_code = 1;
	return (EXIT_FAILURE);
}
