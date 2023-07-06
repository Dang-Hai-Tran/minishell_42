/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_trash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:42:02 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 23:39:46 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Opens a file in write mode, truncates it, and redirects STDERR to it. If any of the operations fail, 
 * it throws an error.
 *
 * @return SUCCESS_FLAG if the redirection is successful, ERROR_FLAG otherwise.
 */
int	redirect_out_trash(void)
{
	int	fd;

	fd = open(TRASH_PATH, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		return (throw_error(TRASH_PATH, NULL, strerror(errno)));
	if (dup2(fd, STDERR_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
