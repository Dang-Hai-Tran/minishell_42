/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:00:11 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:50:06 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Redirect input from a file to the standard input stream. The function takes 
 * in a single parameter, which is a string representing the path to the input 
 * file. The function returns an integer flag indicating whether the operation 
 * was successful or not.
 * @param file_path A string representing the path to the input file
 * @return An integer flag indicating whether the operation was successful or 
 * not. If the function completes successfully, it returns SUCCESS_FLAG, which 
 * is defined as 0. If an error occurs during the operation, the function 
 * prints an error message using the throw_error function and returns -1
*/
int	redirect_in_file(char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY, 0644);
	if (fd < 0)
		return (throw_error(file_path, NULL, strerror(errno)));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (throw_error("dup2", NULL, strerror(errno)));
	if (close(fd) == -1)
		return (throw_error("close", NULL, strerror(errno)));
	return (SUCCESS_FLAG);
}
