/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:05:15 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 11:57:28 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Checks if the signal number passed to it matches the SIGINT signal number and writes a newline character to the input buffer using the ioctl() system call with the TIOCSTI command. It also sets the exit code of the shell to 1.
 * @param signum An integer representing the signal number.
*/
static void	handle_sigint_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_manager.exit_code = 1;
	return ;
}
/**
 * Sets up signal handlers for the SIGINT and SIGQUIT signals during a heredoc input operation. In this function, the SIGINT signal is handled by the handle_sigint_heredoc function, which writes a newline character to the input buffer and sets the exit code of the shell to 1. The SIGQUIT signal is ignored, which means that if it is received during a heredoc input operation, it will be ignored and the operation will continue.
*/
void	heredoc_signal(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
