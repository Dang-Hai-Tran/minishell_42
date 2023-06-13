/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:07 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:56:24 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **argv)
{
	char	*cwd;

	if (*(argv + 1) && check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("pwd", *(argv + 1)));
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (throw_error("pwd", NULL, strerror(errno)));
	ft_putstr_fd(cwd, STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
	free(cwd);
	return (EXIT_SUCCESS);
}
