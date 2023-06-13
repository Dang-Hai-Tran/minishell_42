/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:56:46 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:57:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_unset(char **argv)
{
	t_env	*target;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (!*(argv + 1))
		return (exit_code);
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = throw_error_usage("unset", *argv) + 1;
		else if (ft_strchr(*argv, '='))
			exit_code = throw_error_env("unset", *argv);
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = throw_error_env("unset", *argv);
		else
		{
			target = get_env(*argv);
			if (target)
				remove_env(target);
		}
		argv++;
	}
	return (exit_code);
}
