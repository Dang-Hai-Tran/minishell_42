/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:27:09 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:05:56 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Execute a simple command. The function checks if the command is a built-in 
 * command or a general command and calls the appropriate function to execute 
 * it. If the command is "exit", the function checks for any arguments passed 
 * with it and sets the exit code accordingly.
 * @param simple_command A pointer to a t_simple_command struct that stores 
 * information about the simple command being executed
 * @return An integer value that represents the success or failure of the 
 * command execution
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
			exit_code = check_exit_arg(*(argv + 1));
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
