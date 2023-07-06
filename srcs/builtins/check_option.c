/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:59:05 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if the given command line argument is an option. 
 * An option is identified by a leading dash ('-').
 *
 * @param arg The command line argument to check.
 *
 * @return EXIT_SUCCESS if the given argument is not an option.
 * @return EXIT_FAILURE if the given argument is an option.
 */
int check_option(char *arg)
{
    int exit_code;
    
    if (*arg == '-')
        exit_code = EXIT_FAILURE;
    else
        exit_code = EXIT_SUCCESS;

    return exit_code;
}
