/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:19:19 by datran            #+#    #+#             */
/*   Updated: 2023/06/11 21:50:23 by datran           ###   ########.fr       */
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

void	wait_subshell(pid_t last_pid)
{
	pid_t	pid;
	int		status;

	pid = 0;
	while (pid != ERROR_FLAG)
	{
		pid = waitpid(-1, &status, WUNTRACED);
		if (pid == last_pid)
			set_exit_code(status);
	}
}
