/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:19:19 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 09:47:29 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Waits for all child processes to terminate and sets the global exit code
 * based on the termination status of the last process specified by the
 * last_pid.
 *
 * @param last_pid The PID of the last process in the pipeline.
 */
void	wait_subshell(pid_t last_pid)
{
	pid_t	wpid;
	int		status;
	int		save_status;

	wpid = 0;
	while (wpid != -1 && errno != ECHILD)
	{
		wpid = waitpid(-1, &status, 0);
		if (wpid == last_pid)
			save_status = status;
		continue;
	}
	if (WIFSIGNALED(save_status))
		status = 128 + WTERMSIG(save_status);
	else if (WIFEXITED(save_status))
		status = WEXITSTATUS(save_status);
	else
		status = save_status;
	g_manager.exit_code = status;
}
