/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:53:51 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 16:54:13 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **argv)
{
	t_env	*ptr;

	ptr = g_manager.env;
	if (*(argv + 1))
		return (throw_error_usage("env", *(argv + 1)));
	while (ptr)
	{
		if (ptr->value)
		{
			ft_putstr_fd(ptr->name, STDOUT_FILENO);
			write(STDOUT_FILENO, "=", 1);
			ft_putstr_fd(ptr->value, STDOUT_FILENO);
			write(STDOUT_FILENO, "\n", 1);
		}
		ptr = ptr->next;
	}
	return (EXIT_SUCCESS);
}
