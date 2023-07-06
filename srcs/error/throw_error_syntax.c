/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error_syntax.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:46:57 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 21:34:17 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Prints a syntax error message to the standard error output,
 * and sets the exit code of the shell to EXIT_SYNTAXERR.
 *
 * @param token The token that caused the syntax error.
 *
 * @return ERROR_FLAG always.
 */
int	throw_error_syntax(t_token token)
{
	ft_putstr_fd("msh: syntax error near unexpected token `", STDERR_FILENO);
	if (token.type == T_NULL)
		ft_putstr_fd("newline", STDERR_FILENO);
	else
		ft_putstr_fd(token.value, STDERR_FILENO);
	ft_putendl_fd("'", STDERR_FILENO);
	g_manager.exit_code = EXIT_SYNTAXERR;
	return (ERROR_FLAG);
}
