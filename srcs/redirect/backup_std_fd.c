/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_std_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:25:03 by datran            #+#    #+#             */
/*   Updated: 2023/06/04 12:25:20 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	backup_std_fd(int std_fd[3])
{
	std_fd[READ] = dup2(STDIN_FILENO, BACKUP_FD);
	std_fd[WRITE] = dup(STDOUT_FILENO);
	std_fd[ERROR] = dup(STDERR_FILENO);
	if (std_fd[READ] == -1 || std_fd[WRITE] == -1 || std_fd[ERROR] == -1)
		throw_error_exit("dup", strerror(errno), EXIT_FAILURE);
	return (SUCCESS_FLAG);
}
