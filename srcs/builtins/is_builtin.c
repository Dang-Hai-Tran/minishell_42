/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:44:29 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if a command is a shell built-in command. 
 *
 * @param exec_path The name of the command to check.
 *
 * @return true if the command is a shell built-in command.
 * @return false otherwise.
 */
int	is_builtin(char *exec_path)
{
	if (!sh_strcmp(exec_path, "cd"))
		return (true);
	else if (!sh_strcmp(exec_path, "echo"))
		return (true);
	else if (!sh_strcmp(exec_path, "pwd"))
		return (true);
	else if (!sh_strcmp(exec_path, "env"))
		return (true);
	else if (!sh_strcmp(exec_path, "exit"))
		return (true);
	else if (!sh_strcmp(exec_path, "export"))
		return (true);
	else if (!sh_strcmp(exec_path, "unset"))
		return (true);
	else
		return (false);
}
