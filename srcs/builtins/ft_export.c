/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:54:28 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 12:10:24 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints the shell's environment variables to standard output
 * with quotes around the values. 
 * Each variable is printed in the form of 'name="value"'.
 */
static void	print_environment_with_quotes(void)
{
	t_env	*current_env;

	current_env = g_manager.env;
	while (current_env)
	{
		ft_putstr_fd("declare -x ", STDOUT_FILENO);
		ft_putstr_fd(current_env->name, STDOUT_FILENO);
		if (current_env->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(current_env->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		current_env = current_env->next;
	}
}

/**
 * Executes the 'export' shell command with a single argument. 
 * The argument is a string in the form of 'name=value'. 
 * The function updates the value of the named environment variable, 
 * or adds the variable to the environment if it does not already exist.
 *
 * @param argument The argument string to process.
 */
static void	execute_export(char *argument)
{
	char	*name;
	char	*value;
	char	*tmp;
	t_env	*env_found;

	name = get_env_name(argument);
	value = get_env_value(argument);
	env_found = get_env(name);
	if (env_found)
	{
		tmp = env_found->value;
		env_found->value = value;
		free(tmp);
		free(name);
	}
	else
		add_env(name, value);
}

/**
 * Implements the 'export' shell command, which modifies the shell's
 * environment variables. 
 * The function supports multiple 'name=value' arguments, which are processed
 * in order.
 *
 * @param arguments An array of strings, representing the 'export' command and
 * 	its arguments. 
 * The first element is the command itself ('export'), and the rest are the
 * 	arguments.
 *
 * @return EXIT_SUCCESS if all arguments are processed successfully.
 * @return An error code if any of the arguments is invalid.
 */
int	perform_export(char **arguments)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!arguments[1])
	{
		print_environment_with_quotes();
		return (exit_code);
	}
	arguments++;
	while (*arguments)
	{
		if (check_option(*arguments) == true)
			exit_code = throw_error_usage("export", *arguments) + 1;
		else if (valid_env_name(*arguments) == false)
			exit_code = throw_error_env("export", *arguments);
		else
			execute_export(*arguments);
		arguments++;
	}
	return (exit_code);
}
