/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:59:05 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 12:56:16 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Checks if the given command line argument is an option. 
 * An option is identified by a leading dash ('-').
 *
 * @param arg The command line argument to check.
 *
 * @return true if the given argument is not an option.
 * @return false if the given argument is an option.
 */
int	check_option(char *arg)
{
	int	exit_code;

	if (*arg == '-')
		exit_code = true;
	else
		exit_code = false;
	return (exit_code);
}
