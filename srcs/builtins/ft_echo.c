/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:09 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 10:22:26 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if the provided option for the 'echo' command is valid. 
 * A valid option is "-n", which suppresses the trailing newline. 
 * The function allows repeated 'n' characters after the dash ("-nnn").
 *
 * @param option The option string to check.
 *
 * @return 1 if the option is valid.
 * @return 0 otherwise.
 */
static int	check_echo_option(char *option)
{
	int	flag;
	int	len;
	int	i;

	flag = 0;
	len = ft_strlen(option);
	i = 2;
	if (!ft_strncmp(option, "-n", 2))
	{
		while (i <= len - 1)
		{
			if (option[i] != 'n')
				return (flag);
			i++;
		}
		flag = 1;
	}
	return (flag);
}

/**
 * Implements the 'echo' shell command, which outputs its arguments to the 
 * standard output. The function supports the '-n' option, which suppresses
 * the trailing newline.
 *
 * @param argv An array of strings, representing the 'echo' command and its
 * 	arguments. The first element is the command itself ('echo'), and the
 * 	rest are the arguments.
 *
 * @return EXIT_SUCCESS after printing the arguments to the standard output.
 */
int	echo_command(char **argv)
{
	int	has_newline;

	has_newline = 0;
	argv++;
	if (!*argv)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		return (EXIT_SUCCESS);
	}
	if (check_echo_option(*argv))
	{
		has_newline = 1;
		if (!*(argv + 1))
			return (EXIT_SUCCESS);
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		if (*(argv + 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		argv++;
	}
	if (!has_newline)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
