/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:02:38 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints an error message, sets the exit code of the shell, and terminates the shell.
 *
 * @param cmd The command that caused the error.
 * @param err The error message.
 * @param exit_code The exit code to set.
 *
 * @return EXIT_FAILURE always.
 */
int	throw_error_exit(char *cmd, char *err, int exit_code)
{
	g_manager.exit_code = exit_code;
	throw_error(cmd, NULL, err);
	exit(g_manager.exit_code);
	return (EXIT_FAILURE);
}
