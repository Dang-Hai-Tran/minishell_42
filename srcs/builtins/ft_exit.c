/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:30:00 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:19:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_lld(unsigned long long res, int sign)
{
	if ((res > LONG_MAX && sign > 0) || (res > -(unsigned long)LONG_MIN \
	&& sign < 0))
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
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr)
	{
		res = res * 10 + (*ptr - '0');
		ptr++;
	}
	return (check_lld(res, sign));
}

int	check_exit_arg(char *arg)
{
	char	*ptr;

	ptr = arg;
	if ((*ptr) == '+' || (*ptr) == '-')
		ptr++;
	while (*ptr)
	{
		if (!ft_isdigit(*ptr))
		{
			throw_error("exit", ptr, "numeric argument required");
			exit(2);
		}
		ptr++;
	}
	if (valid_exit_code(arg) == false)
	{
		throw_error("exit", ptr, "numeric argument required");
		exit(2);
	}
	return (ft_atoi(arg));
}

int	ft_exit(char **argv)
{
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	ft_putstr_fd("exit\n", STDERR_FILENO);
	if (*(argv + 1))
	{
		if (*(argv + 2))
			return (throw_error("exit", NULL, "too many arguments"));
		exit_code = check_exit_arg(*(argv + 1));
	}
	free_manager();
	exit(exit_code % 256);
	return (EXIT_FAILURE);
}
