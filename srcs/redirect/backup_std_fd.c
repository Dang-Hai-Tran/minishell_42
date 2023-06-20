/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_std_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:25:03 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 12:02:59 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Backup the standard input, output, and error file descriptors of a process. It takes in an array of integers that represent the standard file descriptors for reading (STDIN_FILENO), writing (STDOUT_FILENO), and error reporting (STDERR_FILENO). The function returns a flag indicating whether the operation was successful or not.
 * @param std_fd[3] An integer array of size 3 that contains the standard file descriptors for reading, writing, and error reporting.
*/
int	backup_std_fd(int std_fd[3])
{
	std_fd[READ] = dup2(STDIN_FILENO, BACKUP_FD);
	std_fd[WRITE] = dup(STDOUT_FILENO);
	std_fd[ERROR] = dup(STDERR_FILENO);
	if (std_fd[READ] == -1 || std_fd[WRITE] == -1 || std_fd[ERROR] == -1)
		throw_error_exit("dup", strerror(errno), EXIT_FAILURE);
	return (SUCCESS_FLAG);
}
