/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:19:19 by datran            #+#    #+#             */
/*   Updated: 2023/07/18 17:25:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_exit_code(int status)
{
	if (WIFEXITED(status))
		g_manager.exit_code = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		g_manager.exit_code = 128 + WTERMSIG(status);
		if (g_manager.exit_code == 131)
			ft_putendl_fd("Quit: 3", STDERR_FILENO);
	}
	else
		g_manager.exit_code = EXIT_FAILURE;
}

/**
 * Waits for all child processes to terminate and sets the global exit code
 * based on the termination status of the last process specified by the
 * last_pid.
 *
 * @param last_pid The PID of the last process in the pipeline.
 */
void	wait_subshell(pid_t last_pid)
{
	pid_t	pid;
	int		status;

	pid = 0;
	while (pid != -1)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (pid == last_pid)
			set_exit_code(status);
	}
}
