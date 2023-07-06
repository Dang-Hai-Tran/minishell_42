/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:11:58 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Restores the standard file descriptors from their backups. If any of the restorations fail, it throws 
 * an error and exits.
 *
 * @param std_fd An array containing the backups of the standard file descriptors.
 *
 * @return SUCCESS_FLAG if the restorations are successful, else it throws an error and exits.
 */
int	reset_std_fd(int std_fd[3])
{
	if (dup2(std_fd[READ], STDIN_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[WRITE], STDOUT_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	if (dup2(std_fd[ERROR], STDERR_FILENO) == -1)
		return (throw_error_exit("dup2", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}
