/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:58:49 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 14:01:08 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Execute an input/output redirection operation. The function checks the type of redirection operation specified in the io_redirect structure and calls the appropriate function to perform the redirection.
 * @param io_redirect A pointer to a t_io_redirect struct that stores information about the input/output redirection being performed
 * @return An integer value that represents the success or failure of the redirection operation
*/
int	exec_io_redirect(t_io_redirect *io_redirect)
{
	t_redirect_op	redirect_op;

	redirect_op = io_redirect->redirect_op;
	if (redirect_op == R_IN || redirect_op == R_HEREDOC)
		return (redirect_in_file(io_redirect->file_path));
	else if (redirect_op == R_OUT)
		return (redirect_out_file(io_redirect->file_path));
	else if (redirect_op == R_APPEND)
		return (redirect_append_file(io_redirect->file_path));
	else
		return (ERROR_FLAG);
}
