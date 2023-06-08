/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:05:15 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:05:30 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint_heredoc(int signum)
{
	if (signum != SIGINT)
		return ;
	ioctl(STDIN_FILENO, TIOCSTI, "\n");
	g_manager.exit_code = 1;
	return ;
}

void	heredoc_signal(void)
{
	signal(SIGINT, handle_sigint_heredoc);
	signal(SIGQUIT, SIG_IGN);
}
