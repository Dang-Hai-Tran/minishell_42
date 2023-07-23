/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:07 by datran            #+#    #+#             */
/*   Updated: 2023/07/22 22:47:47 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Implements the 'pwd' shell command, which prints the current working 
 * directory to standard output. 
 *
 * @param arguments An array of strings, representing the 'pwd' command
 * 	and its arguments. The first element is the command itself ('pwd')
 * 	and the rest are the arguments.
 *
 * @return EXIT_SUCCESS after printing the current working directory.
 * @return An error code if the command is followed by an argument
 * 	which is not supported.
 */
int	perform_pwd(char **arguments)
{
	char	*cwd;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (*(arguments + 1) && check_option(*(arguments + 1)) == true)
		return (throw_error_usage("pwd", *(arguments + 1)));
	cwd = get_env("PWD")->value;
	ft_putendl_fd(cwd, STDOUT_FILENO);
	return (exit_code);
}
