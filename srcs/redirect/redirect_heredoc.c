/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:06:16 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:32:54 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Frees a line and closes a file descriptor. If the close operation fails,
 * it throws an error and exits.
 *
 * @param line The line to be freed.
 * @param fd The file descriptor to be closed.
 *
 * @return SUCCESS_FLAG if the close operation is successful,
 * 	else it throws an error and exits.
 */
static int	end_of_heredoc(char *line, int fd)
{
	free(line);
	if (close(fd) == -1)
		return (throw_error_exit("close", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}

/**
 * Creates a heredoc file, prompts the user to enter lines until a line matches
 * the end text or the user enters EOF (Ctrl-D), and redirects the entered lines
 * to the heredoc file. If any of the operations fail, it throws an error and
 * exits.
 *
 * @param end_text The text that ends the heredoc input.
 * @param heredoc_path The path of the heredoc file.
 *
 * @return SUCCESS_FLAG if the heredoc is created successfully, EXIT_FAILURE
 * 	otherwise.
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
		sh_putline_heredoc(line, fd);
		free(line);
	}
	if (close(fd) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	return (EXIT_FAILURE);
}
