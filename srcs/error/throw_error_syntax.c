/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:57 by datran            #+#    #+#             */
/*   Updated: 2023/06/21 12:24:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	throw_error_syntax(t_token token)
{
	ft_putstr_fd("msh: syntax error near unexpected token `", 2);
	ft_putstr_fd(token.value, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	g_manager.exit_code = EXIT_SYNTAXERR;
	return (ERROR_FLAG);
}
