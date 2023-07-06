/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:47:37 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:09:06 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Handles an execution error occurred due to system level issue such 
 * as file not found or lack of access permissions and logs an error message.
 *
 * @param argv The command that caused the execution error.
 *
 * @return The appropriate exit code based on the nature of the error.
 */
static int	error_execve_sys(char *argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT)
	{
		throw_error(argv, NULL, strerror(errno));
		exit_code = EXIT_ENOENT;
	}
	else if (errno == EACCES)
	{
		throw_error(argv, NULL, strerror(errno));
		exit_code = EXIT_EACCES;
	}
	return (exit_code);
}

/**
 * Handles an execution error occurred due to a local command not being found
 * and logs an appropriate error message.
 *
 * @param argv The command that caused the execution error.
 *
 * @return The exit code indicating the command not found error.
 */
static int	error_execve_local(char *argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT || errno == EACCES)
	{
		throw_error(argv, NULL, "command not found");
		exit_code = EXIT_ENOENT;
	}
	return (exit_code);
}

/**
 * Executes a file as a command by checking the nature of the file and running
 * it with the given command line arguments and environment variables.
 *
 * @param filename The name of the file to execute.
 * @param argv An array of strings representing the command line arguments.
 * @param envp An array of strings representing the environment variables.
 *
 * @return The appropriate exit code based on the result of the command
 * 	execution.
 */
static int	exec_file_name(char *filename, char **argv, char **envp)
{
	if (ft_strchr(filename, '/'))
	{
		if (sh_cmd_is_dir(filename))
		{
			throw_error(filename, NULL, "Is a directory");
			return (EXIT_EACCES);
		}
		execve(filename, argv, envp);
		free(filename);
		return (error_execve_sys(*argv));
	}
	execve(filename, argv, envp);
	free(filename);
	return (error_execve_local(*argv));
}

/**
 * Executes a general command by either finding the command in the PATH 
 * environment variable or treating it as a filename.
 * Then it uses exec_file_name to execute it.
 *
 * @param argv An array of strings representing the command line arguments.
 *
 * @return The appropriate exit code based on the result of the command
 * 	execution.
 */
int	exec_general(char **argv)
{
	char	**envp;
	char	*filename;

	filename = NULL;
	envp = sh_get_string_env();
	if (ft_strchr(*argv, '/') == NULL)
	{
		if (get_env(PATHENV))
			filename = sh_find_path(*argv);
	}
	else
		filename = ft_strdup(*argv);
	if (filename == NULL)
	{
		throw_error(*argv, NULL, "command not found");
		return (EXIT_ENOENT);
	}
	return (exec_file_name(filename, argv, envp));
}
