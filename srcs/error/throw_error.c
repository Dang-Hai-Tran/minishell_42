/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:05:36 by datran            #+#    #+#             */
/*   Updated: 2023/06/04 12:45:56 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Print an error message to the standard error output stream (stderr) in the following format: msh: <cmd>: <argv>: <err>
 * @param cmd A string representing the name of the command that caused the error.
 * @param argv A string representing the arguments passed to the command that caused the error. This parameter can be NULL if no arguments were passed.
 * @param err A string representing the error message.
 * @return An integer value of EXIT_FAILURE, which indicates that an error has occurred.
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
	return (EXIT_FAILURE);
}
