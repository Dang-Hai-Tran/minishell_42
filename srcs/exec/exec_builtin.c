/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:46:55 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:47:10 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_builtin(char **argv)
{
	if (!ft_strncmp(*argv, "echo", 5))
		return (ft_echo(argv));
	if (!ft_strncmp(*argv, "cd", 3))
		return (ft_cd(argv));
	if (!ft_strncmp(*argv, "pwd", 4))
		return (ft_pwd(argv));
	if (!ft_strncmp(*argv, "env", 4))
		return (ft_env(argv));
	if (!ft_strncmp(*argv, "export", 7))
		return (ft_export(argv));
	if (!ft_strncmp(*argv, "unset", 6))
		return (ft_unset(argv));
	if (!ft_strncmp(*argv, "exit", 5))
		ft_exit(argv);
	return (EXIT_FAILURE);
}
