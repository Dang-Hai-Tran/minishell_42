/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_subshell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:06:41 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 11:30:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Closes both ends of the pipe.
 * @param pipe_fd[2] An integer array containing the file descriptors for the read and write ends of the pipe.
*/
void	close_pipe_fd(int pipe_fd[2])
{
	if (close(pipe_fd[0]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	if (close(pipe_fd[1]) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
}
/**
 * Connects the read or write end of a pipe to the appropriate file descriptor for input or output of a command.
 * @param pipe_fd[2] An integer array containing the file descriptors for the read and write ends of the pipe.
 * @param pipe_type An integer value indicating whether to connect the read or write end of the pipe. The value READ is used to connect the read end, while the value WRITE is used to connect the write end.
*/
void	connect_pipe(int pipe_fd[2], int pipe_type)
{
	if (dup2(pipe_fd[pipe_type], pipe_type) == -1)
		throw_error_exit("dup2", strerror(errno), EXIT_FAILURE);
	close_pipe_fd(pipe_fd);
}

/**
 * Creates a subshell process by calling the fork() system call. It also sets up a pipe between the parent and child processes using the pipe() system call. The function then connects the appropriate end of the pipe to the input or output of the command being executed depending on whether it is the first or last command in the pipeline.
 * @param pipe_line A pointer to a structure containing information about the pipeline of commands to be executed.
 * @return The PID (process ID) of the newly created child process.
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
		exit(g_manager.exit_code);
	}
	connect_pipe(pipe_fd, READ);
	return (pid);
}
