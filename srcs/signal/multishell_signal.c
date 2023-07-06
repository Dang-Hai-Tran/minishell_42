/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multishell_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:48:07 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:24:04 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Handles the SIGINT signal while multiple shell commands are being
 * executed concurrently. It simply returns if the signal is not SIGINT,
 * effectively ignoring the signal.
 *
 * @param signum The signal number.
 */
static void	handle_sigint_multishell(int signum)
{
	if (signum != SIGINT)
		return ;
}

/**
 * Handles the SIGQUIT signal while multiple shell commands are being
 * executed concurrently. It simply returns if the signal is not SIGQUIT,
 * effectively ignoring the signal.
 *
 * @param signum The signal number.
 */
static void	handle_sigquit_multishell(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

/**
 * Changes the SIGINT and SIGQUIT signal handlers to handle_sigint_multishell
 * and handle_sigquit_multishell respectively. This is typically used to change
 * the default signal behavior during the concurrent execution of multiple 
 * shell commands.
 */
void	multishell_signal(void)
{
	signal(SIGINT, handle_sigint_multishell);
	signal(SIGQUIT, handle_sigquit_multishell);
}
