/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:30:00 by datran            #+#    #+#             */
/*   Updated: 2023/07/12 17:42:47 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if a long long integer value falls within the range of long int.
 *
 * @param res The long long integer value to check.
 * @param sign The sign of the integer (+1 for positive, -1 for negative).
 *
 * @return true if the integer value falls within the range of long int.
 * @return false otherwise.
 */
static int	is_within_long_range(unsigned long long res, int sign)
{
	if ((res > LONG_MAX && sign > 0) || (res > -(unsigned long)LONG_MIN
			&& sign < 0))
		return (false);
	return (true);
}

/**
 * Checks if a given string can be converted into a valid exit code. 
 * A valid exit code is a numeric string that can be converted into an integer
 * within the range of long int.
 *
 * @param s The string to check.
 *
 * @return true if the string can be converted into a valid exit code.
 * @return false otherwise.
 */
int	is_valid_exit_code(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					sign;

	ptr = (char *)s;
	res = 0;
	sign = 1;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (is_within_long_range(res, sign));
}

/**
 * Checks if a given string is a valid argument for the 'exit' command. 
 * A valid argument is a numeric string that can be converted into an integer
 * within the range of long int.
 *
 * @param arg The string to check.
 *
 * @return The integer representation of the argument if it is valid.
 * @return Exits the program with an error message and exit code 2 if the 
 * argument is invalid.
 */
int	validate_exit_arg(char *arg)
{
	char	*ptr;

	ptr = arg;
	if ((*ptr) == '+' || (*ptr) == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			throw_error("exit", ptr, "numeric argument required");
			exit(2);
		}
		ptr++;
	}
	if (is_valid_exit_code(arg) == false)
	{
		throw_error("exit", ptr, "numeric argument required");
		exit(2);
	}
	return (ft_atoi(arg));
}

/**
 * Implements the 'exit' shell command, which terminates the shell. 
 * The function supports an optional argument, which specifies the exit code.
 *
 * @param argv An array of strings, representing the 'exit' command and its 
 * arguments. The first element is the command itself ('exit'), and the rest 
 * are the arguments.
 *
 * @return EXIT_FAILURE if the command is not followed by an argument.
 * @return Exits the program with the specified exit code if an argument is 
 * provided. The exit code is the modulo of the argument by 256.
 */
int	exit_command(char **argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	//ft_putstr_fd("exit\n", STDERR_FILENO);
	if (*(argv + 1))
	{
		if (*(argv + 2))
			return (throw_error("exit", NULL, "too many arguments"));
		exit_code = validate_exit_arg(*(argv + 1));
	}
	free_manager();
	exit(exit_code % 256);
	return (EXIT_FAILURE);
}
