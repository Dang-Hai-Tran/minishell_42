/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multishell_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 17:48:07 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 13:03:37 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* do nothing */
static void	handle_sigint_multishell(int signum)
{
	if (signum != SIGINT)
		return ;
}

/* do nothing */
static void	handle_sigquit_multishell(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	multishell_signal(void)
{
	signal(SIGINT, handle_sigint_multishell);
	signal(SIGQUIT, handle_sigquit_multishell);
}
