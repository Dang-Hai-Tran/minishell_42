/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:06:16 by datran            #+#    #+#             */
/*   Updated: 2023/07/23 12:42:21 by datran           ###   ########.fr       */
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
static int	end_of_heredoc(char *line, char *end_text_l, int fd)
{
	g_manager.end_heredoc = true;
	free(line);
	free(end_text_l);
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
	char	*end_text_l;

	g_manager.end_heredoc = false;
	fd = open(heredoc_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		throw_error_exit("open", strerror(errno), EXIT_FAILURE);
	end_text_l = ft_strjoin(end_text, "\n");
	while (!g_manager.end_heredoc)
	{
		heredoc_signal();
		ft_putstr_fd("> ", STDOUT_FILENO);
		line = ft_readline(STDIN_FILENO);
		if (!line || !sh_strcmp(line, end_text_l))
			return (end_of_heredoc(line, end_text_l, fd));
		sh_putline_heredoc(line, fd);
		free(line);
	}
	free(end_text_l);
	if (close(fd) == -1)
		throw_error_exit("close", strerror(errno), EXIT_FAILURE);
	return (ERROR_FLAG);
}
