/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:20:51 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:21:07 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_simple_command(t_simple_command *simple_command)
{
	int	ac;

	ac = 0;
	while (simple_command->argv[ac])
		free(simple_command->argv[ac++]);
	free(simple_command->argv);
	free(simple_command);
}
