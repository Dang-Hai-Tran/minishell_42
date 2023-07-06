/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:20:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Frees the memory allocated for a `t_simple_command` structure.
 *
 * @param simple_command Pointer to a `t_simple_command` structure to be freed.
 */
void	free_simple_command(t_simple_command *simple_command)
{
	int	ac;

	ac = -1;
	while (simple_command->argv[++ac])
		free(simple_command->argv[ac]);
	free(simple_command->argv);
	free(simple_command);
}
