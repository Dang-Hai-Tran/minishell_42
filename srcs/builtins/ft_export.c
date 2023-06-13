/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:54:28 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:55:08 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_quotes(void)
{
	t_env	*ptr;

	ptr = g_manager.env;
	while (ptr)
	{
		ft_putstr_fd(ptr->name, STDOUT_FILENO);
		if (ptr->value)
		{
			write(STDOUT_FILENO, "=\"", 2);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\"", 1);
		}
		write(STDOUT_FILENO, "\n", 1);
		ptr = ptr->next;
	}
}

static void	exec_export(char *argv)
{
	char	*name;
	char	*value;
	t_env	*ptr;

	name = get_env_name(argv);
	value = get_env_value(argv);
	ptr = get_env(name);
	if (ptr)
	{
		if (value)
		{
			if (ptr->value)
				free(ptr->value);
			ptr->value = value;
		}
		free(name);
	}
	else
		add_env(name, get_env_value(argv));
}

int	ft_export(char **argv)
{
	int	exit_code;

	exit_code = EXIT_SUCCESS;
	if (!argv[1])
	{
		env_quotes();
		return (exit_code);
	}
	argv++;
	while (*argv)
	{
		if (check_option(*argv) == EXIT_FAILURE)
			exit_code = throw_error_usage("export", *argv) + 1;
		else if (valid_env_name(*argv) == EXIT_FAILURE)
			exit_code = throw_error_env("export", *argv);
		else
			exec_export(*argv);
		argv++;
	}
	return (exit_code);
}
