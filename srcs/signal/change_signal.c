/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 15:11:22 by datran            #+#    #+#             */
/*   Updated: 2023/06/06 15:13:29 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	handle_sigint_change(int signum)
{
	if (signum != SIGINT)
		return ;
	write(1, "\n", 1);
}

static void	handle_sigquit_change(int signum)
{
	if (signum != SIGQUIT)
		return ;
}

void	change_signal(void)
{
	signal(SIGINT, handle_sigint_change);
	signal(SIGQUIT, handle_sigquit_change);
}
