/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_io_redirect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:20:06 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:20:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_io_redirect(t_io_redirect *io_redirect)
{
	if (io_redirect->redirect_op == R_HEREDOC)
		unlink(io_redirect->file_path);
	if (io_redirect->file_path)
		free(io_redirect->file_path);
	if (io_redirect->end_text)
		free(io_redirect->end_text);
	free(io_redirect);
}
