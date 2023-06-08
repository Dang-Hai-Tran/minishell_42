/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:02:38 by datran            #+#    #+#             */
/*   Updated: 2023/06/04 16:32:30 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Print an error message to the standard error output stream (stderr) and then exit the program with the specified exit code.
 * @param cmd A string representing the name of the command that caused the error.
 * @param err A string representing the error message.
 * @param exit_code An integer representing the exit code to be returned by the program.
 * @return An integer value of EXIT_FAILURE, which indicates that an error has occurred.
*/
int	throw_error_exit(char *cmd, char *err, int exit_code)
{
	g_manager.exit_code = exit_code;
	throw_error(cmd, NULL, err);
	exit(g_manager.exit_code);
	return (EXIT_FAILURE);
}
