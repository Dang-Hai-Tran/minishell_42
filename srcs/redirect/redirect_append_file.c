/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_append_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:03:23 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:49:34 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Redirect the standard output (STDOUT_FILENO) of a process to append data to 
 * a specified file. It takes in a string representing the path to the file to 
 * which the output should be redirected. The function returns a flag 
 * indicating whether the operation was successful or not.
 * @param file_path A string representing the path to the file to which the 
 * output should be appended.
 * @return An integer flag that indicates whether the operation was successful 
 * or not. The flag is defined as SUCCESS_FLAG, which is equal to 0.
*/
int	redirect_append_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
