/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:11:22 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 11:49:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Checks if the signal number passed to it matches the SIGINT signal number and writes a newline character to standard output if it does.
 * @param signum An integer representing the signal number.
*/
static void	handle_sigint_change(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}
/**
 * Checks if the signal number passed to it matches the SIGQUIT signal number and returns if it does not match.
 * @param signum An integer representing the signal number.
*/
static void	handle_sigquit_change(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/**
 * Changes the signal handlers for the SIGINT and SIGQUIT signals to custom handler functions.
*/
void	change_signal(void)
{
	signal(SIGINT, handle_sigint_change);
	signal(SIGQUIT, handle_sigquit_change);
}
