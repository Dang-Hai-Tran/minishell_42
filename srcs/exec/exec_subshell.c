/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:03:50 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 11:40:58 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_subshell(t_pipe_line *pipe_line)
{
	pid_t	pid;

	pid = create_subshell(pipe_line);
	if (pid == ERROR_FLAG)
		return (ERROR_FLAG);
	if (pipe_line->pipe_line && pipe_line->pipe_line->type == AST_PIPELINE)
		exec_subshell(pipe_line->pipe_line->data);
	wait_subshell(pid);
	return (SUCCESS_FLAG);
}
