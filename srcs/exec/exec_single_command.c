/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_single_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:46:40 by datran            #+#    #+#             */
/*   Updated: 2023/06/26 15:25:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_single_general(t_simple_command *simple_command)
{
	pid_t	pid;
	int		exit_code;

	if (simple_command && !sh_strcmp(*(simple_command->argv), "./minishell"))
		multishell_signal();
	else
		change_signal();
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		exit_code = exec_general(simple_command->argv);
		g_manager.exit_code = exit_code;
		exit(g_manager.exit_code);
	}
	else
		wait_subshell(pid);
	return (SUCCESS_FLAG);
}

static int	exec_single_builtin(t_simple_command *simple_command)
{
	int	exit_code;

	exit_code = exec_builtin(simple_command->argv);
	g_manager.exit_code = exit_code;
	if (exit_code == EXIT_SUCCESS)
		return (SUCCESS_FLAG);
	else
		return (ERROR_FLAG);
}

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
