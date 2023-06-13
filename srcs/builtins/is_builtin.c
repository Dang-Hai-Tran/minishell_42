/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:44:29 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:45:34 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
