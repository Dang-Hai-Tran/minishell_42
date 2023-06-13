/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:09 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:53:26 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_echo_option(char *option)
{
	int	flag;
	int	i;

	flag = 0;
	i = 2;
	if (!ft_strncmp(option, "-n", i))
	{
		while (option[i] == 'n')
			i++;
		if (option[i])
			flag = 0;
		else
			flag = 1;
	}
	return (flag);
}

int	ft_echo(char **argv)
{
	int	flag;

	flag = 0;
	argv++;
	while (check_echo_option(*argv))
	{
		flag = 1;
		argv++;
	}
	while (*argv)
	{
		ft_putstr_fd(*argv, STDOUT_FILENO);
		if (*(argv + 1))
			ft_putstr_fd(" ", STDOUT_FILENO);
		argv++;
	}
	if (!flag)
		ft_putstr_fd("\n", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
