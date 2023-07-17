/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:46:55 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 10:22:53 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes a built-in command by comparing the given command name with a list 
 * of known built-in commands, and calling the corresponding function.
 *
 * @param argv An array of strings representing the command line arguments.
 *
 * @return 1 if the built-in command is executed successfully, otherwise
 * 	returns the exit failure code.
 */
int	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "echo", 5))
		return (echo_command(argv));
	if (!ft_strncmp(*argv, "cd", 3))
		return (change_directory(argv));
	if (!ft_strncmp(*argv, "pwd", 4))
		return (perform_pwd(argv));
	if (!ft_strncmp(*argv, "env", 4))
		return (env_command(argv));
	if (!ft_strncmp(*argv, "export", 7))
		return (perform_export(argv));
	if (!ft_strncmp(*argv, "unset", 6))
		return (perform_unset(argv));
	if (!ft_strncmp(*argv, "exit", 5))
		exit_command(argv);
	return (EXIT_FAILURE);
}
