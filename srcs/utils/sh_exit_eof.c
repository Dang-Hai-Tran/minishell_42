/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit_eof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:05:26 by datran            #+#    #+#             */
/*   Updated: 2023/07/12 13:19:12 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Exits the shell if an end of file (EOF) is encountered.
 *
 * @param command_line The command line string.
 */
void	sh_exit_eof(char *command_line)
{
	if (!command_line)
	{
		//ft_putstr_fd("exit\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}
