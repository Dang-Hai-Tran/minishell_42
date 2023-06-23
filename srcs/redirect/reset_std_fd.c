/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_std_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:11:58 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:50:49 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Reset the standard input, output and error file descriptors to their 
 * original values.
 * @param std_fd[3] An array of three integers representing the original file 
 * descriptors for the standard input, output and error streams
 * @return An integer flag indicating whether the operation was successful or 
 * not. If the function completes successfully, it returns SUCCESS_FLAG, which 
 * is defined as 0. If an error occurs during the operation, the function 
 * prints an error message using the throw_error_exit function and returns an 
 * integer flag indicating failure.
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
