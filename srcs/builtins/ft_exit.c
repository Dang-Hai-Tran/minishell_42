/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:30:00 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 16:49:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_lld(unsigned long long res, int sign)
{
	if (res > 9223372036854775807UL && sign > 0)
		return (false);
	if (res > 9223372036854775808UL && sign < 0)
		return (false);
	return (true);
}

int	valid_exit_code(const char *s)
{
	char				*ptr;
	unsigned long long	res;
	int					sign;

	ptr = (char *)s;
	res = 0;
	sign = 1;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		if (res > res * 10 + (*ptr - '0'))
			return (false);
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (check_lld(res, sign));
}

unsigned char	check_exit_arg(char *arg)
{
	char	*ptr;

	ptr = arg;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			throw_error("exit", ptr, "numeric argument required");
			exit(EXIT_MAX);
		}
		ptr++;
	}
	if (valid_exit_code(arg) == false)
	{
		throw_error("exit", ptr, "numeric argument required");
		exit(EXIT_MAX);
	}
	return (ft_atoi(arg));
}

int	ft_exit(char **argv)
{
	unsigned char	exit_code;

	exit_code = EXIT_SUCCESS;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (*(argv + 1))
	{
		exit_code = check_exit_arg(*(argv + 1));
		if (*(argv + 2))
			return (throw_error("exit", NULL, "too many arguments"));
	}
	free_env();
	free_ast(g_manager.ast);
	exit(exit_code);
	return (EXIT_FAILURE);
}
