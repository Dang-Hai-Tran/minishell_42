/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_subshell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:03:50 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 23:15:12 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes a pipeline of commands by creating a subshell.
 *
 * @param pipe_line Pointer to a `t_pipe_line` structure containing the pipeline of commands.
 *
 * @return SUCCESS_FLAG if the pipeline is executed successfully, ERROR_FLAG otherwise.
 */
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
