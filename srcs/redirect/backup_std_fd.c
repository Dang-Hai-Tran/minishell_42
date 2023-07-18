/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_std_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 12:25:03 by datran            #+#    #+#             */
/*   Updated: 2023/07/18 17:36:42 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Backs up the standard file descriptors by duplicating them and storing the
 * duplicates in an array.If any of the duplications fail, it throws an error
 * and exits.
 *
 * @param std_fd An array where the backups of the standard file descriptors are
 * 	stored.
 *
 * @return SUCCESS_FLAG if the backups are successful, else it throws an error
 * 	and exits.
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
