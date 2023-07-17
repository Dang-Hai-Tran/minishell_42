/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:06:41 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 09:40:14 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Closes both read and write ends of a pipe. Throws an error and exits if
 * any of the close operations fail.
 *
 * @param pipe_fd An array containing the file descriptors of the pipe ends.
 */
void	close_pipe_fd(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	if (close(pipe_fd[1]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
}

/**
 * Duplicates the specified pipe file descriptor to the specified type
 * (STDIN_FILENO or STDOUT_FILENO). Then it closes both ends of the pipe.
 * Throws an error and exits if any of the operations fail.
 *
 * @param pipe_fd An array containing the file descriptors of the pipe ends.
 * @param pipe_type The type of pipe (read or write end).
 */
void	connect_pipe(int pipe_fd[2], int pipe_type)
{
	if (dup2(pipe_fd[pipe_type], pipe_type) == -1)
		throw_error_exit("dup2", strerror(errno), EXIT_FAILURE);
	close_pipe_fd(pipe_fd);
}

/**
 * Creates a child process that runs a command. It sets up a pipe between
 * the parent and the child process if there's more command in the pipeline.
 * Throws an error and exits if any of the operations fail.
 *
 * @param pipe_line The command to run in the child process.
 * @return Returns the PID of the child process, or ERROR_FLAG if an error
 * occurs.
 */
pid_t	create_subshell(t_pipe_line *pipe_line)
{
	static int	pipe_fd[2];
	pid_t		pid;

	if (pipe(pipe_fd) == -1)
	{
		throw_error("pipe", NULL, strerror(errno));
		return (ERROR_FLAG);
	}
	change_signal();
	pid = fork();
	if (pid < 0)
		throw_error_exit("fork", strerror(errno), EXIT_FAILURE);
	else if (pid == 0)
	{
		if (pipe_line->pipe_line)
			connect_pipe(pipe_fd, WRITE);
		else
			close_pipe_fd(pipe_fd);
		exec_ast(pipe_line->command);
		free_manager();
		exit(g_manager.exit_code);
	}
	connect_pipe(pipe_fd, READ);
	return (pid);
}
