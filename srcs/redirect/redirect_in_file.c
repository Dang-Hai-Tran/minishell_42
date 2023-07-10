/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:00:11 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:32:11by dcolin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Opens a file in read mode and redirects STDIN to it.
 * If any of the operations fail, it throws an error.
 *
 * @param file_path The path of the file to redirect STDIN from.
 *
 * @return SUCCESS_FLAG if the redirection is successful, ERROR_FLAG otherwise.
 */
int	redirect_in_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY, 0644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
