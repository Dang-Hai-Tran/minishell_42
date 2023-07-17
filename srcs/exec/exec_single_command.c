/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:46:40 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 09:51:43 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes a general command (i.e., not a built-in command) by
 * forking a child process and running the command in the child process.
 *
 * @param simple_command Pointer to a `t_simple_command` structure containing
 * 	the command to be executed.
 *
 * @return SUCCESS_FLAG if the command is executed successfully.
 */
static int	exec_single_general(t_simple_command *simple_command)
{
	pid_t	pid;

	if (simple_command && !sh_strcmp(*(simple_command->argv), "./minishell"))
		multishell_signal();
	else
		change_signal();
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		g_manager.exit_code = exec_general(simple_command->argv);
		free_manager();
		exit(g_manager.exit_code);
	}
	wait_subshell(pid);
	return (SUCCESS_FLAG);
}

/**
 * Executes a general command (i.e., not a built-in command) by forking a 
 * child process and running the command in the child process.
 *
 * @param simple_command Pointer to a `t_simple_command` structure containing
 * 	the command to be executed.
 *
 * @return SUCCESS_FLAG if the command is executed successfully.
 */
static int	exec_single_builtin(t_simple_command *simple_command)
{

	g_manager.exit_code = exec_builtin(simple_command->argv);
	if (g_manager.exit_code == EXIT_SUCCESS)
		return (SUCCESS_FLAG);
	else
		return (ERROR_FLAG);
}

/**
 * Executes a built-in command using the `exec_builtin` function and updates
 * 	the global manager exit code.
 *
 * @param simple_command Pointer to a `t_simple_command` structure containing
 * 	the built-in command to be executed.
 *
 * @return SUCCESS_FLAG if the command is executed successfully,
 * 	ERROR_FLAG otherwise.
 */
int	exec_single_command(t_command *command)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (command->redirects)
		flag = exec_ast(command->redirects);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (command->simple_command
		&& is_builtin(command->simple_command->exec_path))
		return (exec_single_builtin(command->simple_command));
	else if (command->simple_command)
		return (exec_single_general(command->simple_command));
	return (flag);
}
