/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:05:15 by datran            #+#    #+#             */
/*   Updated: 2023/07/23 01:41:40 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Handles the SIGINT signal while a heredoc is being read. If the signal is 
 * SIGINT, it simulates a newline input and sets the exit code to 1, 
 * effectively ending the heredoc input. Otherwise, it does nothing.
 *
 * @param signum The signal number.
 */
static void	handle_sigint_heredoc(int signum)
{
	int		ret;

	if (signum != SIGINT)
		return ;
	ret = ioctl(STDIN_FILENO, TIOCSTI, "\n");
	if (ret == -1)
		throw_error("ioctl", NULL, strerror(errno));
	g_manager.exit_code = 130;
	g_manager.end_heredoc = true;
	return ;
}

/**
 * Changes the SIGINT signal handler to handle_sigint_heredoc and 
 * ignores the SIGQUIT signal. This is typically used to change 
 * the default signal behavior during the reading of a heredoc.
 */
void	heredoc_signal(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
