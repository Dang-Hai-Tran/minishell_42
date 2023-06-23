/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_trash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:42:02 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:50:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Redirect output from the standard error stream to a trash file. The function 
 * creates a new file or truncates an existing one, writes all output to the 
 * file and then closes it. The function returns an integer flag indicating 
 * whether the operation was successful or not.
 * @return An integer flag indicating whether the operation was successful or 
 * not. If the function completes successfully, it returns SUCCESS_FLAG, which 
 * is defined as 0. If an error occurs during the operation, the function 
 * prints an error message using the throw_error function and returns -1
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
