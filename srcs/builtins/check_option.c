/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 23:59:05 by datran            #+#    #+#             */
/*   Updated: 2023/06/07 23:59:29 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_option(char *argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (*argv == '-')
		exit_code = EXIT_FAILURE;
	return (exit_code);
}
