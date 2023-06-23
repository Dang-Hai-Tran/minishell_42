/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:09:03 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:53:13 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Handle the SIGINT signal (generated when the user presses Ctrl+C) in the 
 * shell program. The function takes as input the signal number (signum). If 
 * the signum argument is not equal to SIGINT, the function returns without 
 * doing anything. Otherwise, the function writes a newline character to the 
 * standard output, replaces the current command line with an empty string, 
 * moves the cursor to a new line, and redisplay the prompt. It also sets the 
 * exit code of the shell program to 1.
 * @param signum An integer representing the signal number.
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
 * Set up the signal handlers for the shell program. The function sets up two 
 * signal handlers:
 * - The SIGINT signal handler is set to handle_sigint, which is a function that
 * handles the interrupt signal (generated when the user presses Ctrl+C).
 * - The SIGQUIT signal handler is set to ignore the signal, using the SIG_IGN 
 * constant.
*/
void	init_signal(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}
