/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exit_eof.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 17:05:26 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 13:10:46 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Exit the shell program if the user enters an end-of-file (EOF) character as 
 * input. If the command_line argument is NULL, the function prints "exit" to 
 * the standard error output and exits the shell program with a success status 
 * code.
 * @param command_line A pointer to a string representing the command line 
 * input.
*/
void	sh_exit_eof(char *command_line)
{
	if (!command_line)
	{
		ft_putstr_fd("exit\n", STDERR_FILENO);
		exit(EXIT_SUCCESS);
	}
}
