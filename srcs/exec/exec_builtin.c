/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:46:55 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 12:27:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Execute built-in commands of a shell.
 * @param argv An array of strings containing the command and its arguments
 * @return An integer value representing the exit status of the command. If the command is executed successfully, the function returns EXIT_SUCCESS. If there is an error during execution, the function returns EXIT_FAILURE
*/
int	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "echo", 5))
		return (ft_echo(argv));
	if (!ft_strncmp(*argv, "cd", 3))
		return (ft_cd(argv));
	if (!ft_strncmp(*argv, "pwd", 4))
		return (ft_pwd(argv));
	if (!ft_strncmp(*argv, "env", 4))
		return (ft_env(argv));
	if (!ft_strncmp(*argv, "export", 7))
		return (ft_export(argv));
	if (!ft_strncmp(*argv, "unset", 6))
		return (ft_unset(argv));
	if (!ft_strncmp(*argv, "exit", 5))
		ft_exit(argv);
	return (EXIT_FAILURE);
}
