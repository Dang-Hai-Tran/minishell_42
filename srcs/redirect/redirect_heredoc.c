/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:06:16 by datran            #+#    #+#             */
/*   Updated: 2023/06/12 23:20:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	end_of_heredoc(char *line, int fd)
{
	free(line);
	if (close(fd) == -1)
		return (throw_error_exit("close", strerror(errno), EXIT_FAILURE));
	return (SUCCESS_FLAG);
}

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
