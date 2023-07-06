/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:58:49 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:02:29 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes an IO redirection based on the type of the redirection operation.
 *
 * @param io_redirect Pointer to a t_io_redirect object representing the IO
 * 	redirection.
 *
 * @return A flag indicating success if the redirection is executed
 * 	successfully, otherwise returns an error flag.
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
