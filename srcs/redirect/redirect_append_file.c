/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_append_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:03:23 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 17:03:40 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	redirect_append_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 00644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
