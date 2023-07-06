/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:02:28 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 23:39:27 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Opens a file in write mode, truncates it, and redirects STDOUT to it. If any of the operations fail, 
 * it throws an error.
 *
 * @param file_path The path of the file to redirect STDOUT to.
 *
 * @return SUCCESS_FLAG if the redirection is successful, ERROR_FLAG otherwise.
 */
int	redirect_out_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
