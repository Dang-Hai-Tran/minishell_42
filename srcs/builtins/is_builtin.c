/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:44:29 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 14:46:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Determine if a given command is a built-in command or not. The function takes the path of the command as an argument and checks if it matches any of the supported built-in commands.
 * @param exec_path A pointer to a character array that stores the path of the command being checked
 * @return An integer value that represents whether the command is a built-in command or not. If the command is a built-in command, the function returns true (1). Otherwise, it returns false (0).
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
