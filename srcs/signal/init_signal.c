/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:09:03 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:27:20 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

/**
 * Handles the SIGINT signal while a command line is being read. 
 * If the signal is SIGINT, it writes a newline character to the standard 
 * output, resets the readline, and sets the exit code to 1. 
 * Otherwise, it does nothing.
 *
 * @param signum The signal number.
 */
static void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	g_manager.exit_code = 1;
}

/**
 * Changes the SIGINT signal handler to handle_sigint and ignores the SIGQUIT 
 * signal. This is typically used to change the default signal behavior during
 * the reading of a command line.
 */
void	init_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
