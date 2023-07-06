/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:11:22 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:24:44 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Handles the SIGINT signal while a command is being executed. 
 * It writes a newline character to the standard output if the signal is 
 * SIGINT, otherwise, it does nothing.
 *
 * @param signum The signal number.
 */
static void	handle_sigint_change(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

/**
 * Handles the SIGQUIT signal while a command is being executed. 
 * It simply returns if the signal is not SIGQUIT, effectively ignoring the 
 * signal.
 *
 * @param signum The signal number.
 */
static void	handle_sigquit_change(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/**
 * Changes the SIGINT and SIGQUIT signal handlers to handle_sigint_change 
 * and handle_sigquit_change respectively. This is typically used to 
 * change the default signal behavior during the execution of a command.
 */
void	change_signal(void)
{
	signal(SIGINT, handle_sigint_change);
	signal(SIGQUIT, handle_sigquit_change);
}
