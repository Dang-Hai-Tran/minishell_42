/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:29:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/10 12:54:59 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Updates the current working directory of the shell to a given directory path
 * This is accomplished by updating the 'value' field of the provided 'pwd'
 * structure with the current working directory. The function uses getcwd()
 * function to fetch the current working directory.
 *
 * @param pwd Pointer to a t_env structure. The 'value' field of this structure
 * is expected to contain the current working directory of the shell.
 *
 * @return EXIT_SUCCESS if the operation is successful.
 * @return EXIT_FAILURE if the operation fails or if 'pwd' is NULL.
 */
static int	update_current_directory(t_env *pwd)
{
	char	*previous_directory;

	if (!pwd)
		return (EXIT_FAILURE);
	previous_directory = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
		return (throw_error_exit("getcwd", strerror(errno), EXIT_FAILURE));
	if (previous_directory)
		free(previous_directory);
	return (EXIT_SUCCESS);
}

/**
 * Changes the current working directory of the shell to the user's home
 * directory. 
 * The home directory is obtained from the "HOME" environment variable. If the 
 * change is successful, the function also updates the "PWD" environment 
 * variable to reflect the new current working directory.
 *
 * @return EXIT_SUCCESS if the operation is successful.
 * @return An error code if the operation fails, which includes failing to find
 * the "HOME" environment variable.
 */
static int	change_to_home_directory(void)
{
	t_env	*home_env;
	char	*home_directory;
	int		exit_code;

	home_env = get_env("HOME");
	if (!home_env)
		return (throw_error("cd", NULL, strerror(errno)));
	home_directory = home_env->value;
	exit_code = chdir(home_directory);
	if (exit_code < 0)
		return (throw_error("cd", NULL, strerror(errno)));
	exit_code = update_current_directory(get_env("PWD"));
	return (EXIT_SUCCESS);
}

/**
 * Handles the 'cd' shell command, which changes the current working directory 
 * of the shell. The function supports three types of 'cd' commands:
 *  - 'cd' with no arguments changes the working directory to the user's home 
 * directory.
 *  - 'cd -' changes the working directory to the previous working directory.
 *  - 'cd <directory>' changes the working directory to the specified directory
 *
 * @param argv An array of strings, representing the 'cd' command and its
 * 	arguments.
 * The first element is the command itself ('cd'), and the rest
 * 	are the arguments.
 *
 * @return EXIT_SUCCESS if the operation is successful.
 * @return An error code if the operation fails, which includes invalid
 * 	arguments or an inaccessible target directory.
 */
int	change_directory(char **argv)
{
	int	exit_code;

	if (*(argv + 2))
		return (throw_error("cd", NULL, "too many arguments"));
	if (!*(argv + 1))
		return (change_to_home_directory());
	if (check_option(*(argv + 1)) == EXIT_FAILURE)
		return (throw_error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (throw_error("cd", *(argv + 1), strerror(errno)));
	exit_code = update_current_directory(get_env("PWD"));
	return (exit_code);
}
