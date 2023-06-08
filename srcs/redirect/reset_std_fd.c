/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:11:58 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:12:35 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
