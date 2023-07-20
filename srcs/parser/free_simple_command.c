/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:20:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/20 11:00:31 by datran           ###   ########.fr       */
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
	int		i;
	char	**argv;

	i = 0;
	argv = simple_command->argv;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
	free(simple_command);
}
