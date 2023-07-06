/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:27:09 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 00:37:59 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes a simple command within the shell environment. If the command is
 * 'exit', it will process it specially. If the command is a built-in command,
 * it will execute it using the `exec_builtin` function. For general commands,
 * it will use the `exec_general` function. The function also handles exit code 
 * management.
 *
 * @param simple_command Pointer to a `t_simple_command` structure containing the command to be executed.
 *
 * @return SUCCESS_FLAG if the command is executed successfully, ERROR_FLAG otherwise.
 */
int	exec_simple_command(t_simple_command *simple_command)
{
	int		exit_code;
	char	**argv;

	if (!sh_strcmp(simple_command->exec_path, "exit"))
	{
		argv = simple_command->argv;
		if (*(argv + 1))
		{
			exit_code = validate_exit_arg(*(argv + 1));
			if (*(argv + 2))
				return (throw_error("exit", NULL, "too many arguments"));
		}
		redirect_out_trash();
	}
	if (is_builtin(simple_command->exec_path))
		exit_code = exec_builtin(simple_command->argv);
	else
		exit_code = exec_general(simple_command->argv);
	g_manager.exit_code = exit_code;
	if (exit_code == EXIT_SUCCESS)
		return (SUCCESS_FLAG);
	else
		return (ERROR_FLAG);
}
