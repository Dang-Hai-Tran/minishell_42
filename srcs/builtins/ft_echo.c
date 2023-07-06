/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:09 by datran            #+#    #+#             */
/*   Updated: 2023/07/05 10:58:20 by copeugne         ###   ########.fr       */
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
static int is_echo_option_valid(char *option)
{
	int flag = 0;
	int index = 2;

	if (!ft_strncmp(option, "-n", index))
	{
		while (option[index] == 'n')
			index++;
		if (!option[index]) 
			flag = 1;
	}

	return flag;
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
int echo_command(char **argv)
{
	int is_newline_suppressed = 0;

	argv++;
	while (is_echo_option_valid(*argv))
	{
		is_newline_suppressed = 1;
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		if (*(argv + 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		argv++;
	}
	if (!is_newline_suppressed)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return EXIT_SUCCESS;
}
