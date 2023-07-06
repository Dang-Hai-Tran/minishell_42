/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_usage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:13:30 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints an error message related to command usage to the standard error output,
 * and sets the exit code of the shell to 1.
 *
 * @param cmd The command that was used incorrectly.
 * @param argv The argument that was used incorrectly.
 *
 * @return EXIT_FAILURE always.
 */
int	throw_error_usage(char *cmd, char *argv)
{
	ft_putstr_fd("msh: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	write(STDERR_FILENO, argv, 2);
	ft_putstr_fd(": invalid option\n", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd(": usage: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	g_manager.exit_code = 1;
	return (EXIT_FAILURE);
}
