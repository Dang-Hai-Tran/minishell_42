/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:29:51 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 11:59:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Update the value of the PWD environment variable with the current working 
 * directory of the shell.
 * @param pwd A pointer to an environment variable structure representing the 
 * PWD environment variable.
 * @return An integer value that represents the exit status of the function. If 
 * the function is successful, it returns EXIT_SUCCESS. Otherwise, it returns a 
 * non-zero value.
*/
static int	change_pwd(t_env *pwd)
{
	char	*tmp;

	if (!pwd)
		return (EXIT_FAILURE);
	tmp = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
		return (throw_error_exit("getcwd", strerror(errno), EXIT_FAILURE));
	if (tmp)
		free(tmp);
	return (EXIT_SUCCESS);
}

/**
 * Change the current working directory of the shell to the user's home 
 * directory.
 * @return An integer value that represents the exit status of the function. If 
 * the function is successful, it returns EXIT_SUCCESS. Otherwise, it returns a 
 * non-zero value.
*/
static int	cd_home(void)
{
	t_env	*ptr;
	char	*home;
	int		exit_code;

	ptr = get_env("HOME");
	if (!ptr)
		return (throw_error("cd", NULL, strerror(errno)));
	home = ptr->value;
	exit_code = chdir(home);
	if (exit_code < 0)
		return (throw_error("cd", NULL, strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (EXIT_SUCCESS);
}

/**
 * Change the current working directory of the shell. The function takes an 
 * array of strings as an argument that contains the command and its arguments.
 * @param argv A pointer to a null-terminated array of strings that contains 
 * the command and its arguments
 * @return An integer value that represents the exit status of the function. If 
 * the function is successful, it returns 0. Otherwise, it returns a non-zero 
 * value.
*/
int	ft_cd(char **argv)
{
	int	exit_code;

	if (*(argv + 2))
		return (throw_error("cd", NULL, "too many arguments"));
	if (!*(argv + 1))
		return (cd_home());
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (throw_error("cd", *(argv + 1), strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (exit_code);
}
