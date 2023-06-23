/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:02:28 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:50:23 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Redirect output from the standard output stream to a file. The function 
 * takes in a single parameter, which is a string representing the path to the 
 * output file. The function returns an integer flag indicating whether the 
 * operation was successful or not.
 * @param file_path A string representing the path to the output file
 * @return Returns an integer flag indicating whether the operation was 
 * successful or not. If the function completes successfully, it returns 
 * SUCCESS_FLAG, which is defined as 0. If an error occurs during the 
 * operation, the function prints an error message using the throw_error 
 * function and returns -1.
*/
int	redirect_out_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
