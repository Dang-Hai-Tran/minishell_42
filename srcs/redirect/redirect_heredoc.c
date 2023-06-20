/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:06:16 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 12:12:25 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Handle the end of a heredoc input.The function takes in two parameters: a string representing the last user input line and an integer file descriptor representing the file where the input should be stored. The function returns an integer flag indicating whether the operation was successful or not.
 * @param line A string representing the last line of user input before the end text
 * @param fd An integer file descriptor representing the file where the user input should be stored
*/
static int	end_of_heredoc(char *line, int fd)
{
	free(line);
	if (close(fd) == -1)
		return (throw_error_exit("close", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}

/**
 * Redirect the standard output (STDOUT_FILENO) of a process to append data to a specified file. It takes in a string representing the path to the file to which the output should be redirected. The function returns a flag indicating whether the operation was successful or not.
 * @param end_text A string representing the text that signals the end of the user input
 * @param heredoc_path A string representing the path to the file where the user input should be stored.
*/
int	redirect_heredoc(char *end_text, char *heredoc_path)
{
	int		fd;
	char	*line;

	heredoc_signal();
	fd = open(heredoc_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		throw_error_exit("open", strerror(errno), EXIT_FAILURE);
	while (!g_manager.exit_code)
	{
		line = readline("heredoc> ");
		if (!line || !sh_strcmp(line, end_text))
			return (end_of_heredoc(line, fd));
		ft_putendl_fd(line, fd);
		free(line);
	}
	if (close(fd) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	return (EXIT_FAILURE);
}
