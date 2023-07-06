/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:07 by datran            #+#    #+#             */
/*   Updated: 2023/07/05 11:24:40 by colin            ###   ########.fr       */
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
int perform_pwd(char **arguments)
{
    char *cwd;
    int exit_code;

    exit_code = EXIT_SUCCESS;
    if (*(arguments + 1) && check_option(*(arguments + 1)) == EXIT_FAILURE)
        return (throw_error_usage("pwd", *(arguments + 1)));
    cwd = getcwd(NULL, 0);
    if (!cwd)
        return (throw_error("pwd", NULL, strerror(errno)));
    ft_putstr_fd(cwd, STDOUT_FILENO);
    ft_putstr_fd("\n", STDOUT_FILENO);
    free(cwd);
    return (exit_code);
}
