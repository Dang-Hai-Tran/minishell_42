/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:47:37 by datran            #+#    #+#             */
/*   Updated: 2023/06/26 11:23:23 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
 * Executes the given command. It checks if the command is present in the 
 * system path or not, and then executes it using the execve() system call.
 * @param argv A pointer to a char array that contains the command and its 
 * arguments
 * @return An integer value indicating the success or failure of the execution
*/
int	exec_general(char **argv)
{
	char	**envp;
	char	*filename;

	envp = sh_get_string_env();
	if (ft_strchr(*argv, '/') == NULL)
	{
		if (get_env(PATHENV))
			filename = sh_find_path(*argv);
	}
	else
		filename = ft_strdup(*argv);
	return (exec_file_name(filename, argv, envp));
}
