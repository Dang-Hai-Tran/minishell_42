/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:03:34 by datran            #+#    #+#             */
/*   Updated: 2023/07/22 23:16:30 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Matches a token type with the type of the current token. If they match, it
 * returns the token value, else it throws a syntax error.
 *
 * @param type The expected token type.
 *
 * @return The value of the token if the types match, NULL otherwise.
 */
char	*match(t_type type)
{
	t_token	token;

	token = fetch_token(GET);
	fetch_token(UPDATE);
	if (token.type == type)
		return (token.value);
	else
	{
		throw_error_syntax(token);
		free_token(&token);
	}
	return (NULL);
}

/**
 * Implements the syntax analyzer of the command line interpreter.
 * It fetches a token and checks its type. If the type is T_NULL,
 * it returns the abstract syntax tree (AST).
 * If the parsing of the syntax_pipe_line is successful, it updates the exit
 * code of the manager and returns the AST.
 *
 * @return A pointer to the AST.
 */
t_ast	*syntax_analyzer(void)
{
	t_ast	*ast;
	t_token	token;

	ast = NULL;
	fetch_token(UPDATE);
	token = fetch_token(GET);
	if (token.type == T_NULL)
		return (ast);
	if (syntax_pipe_line(&ast) == SUCCESS_FLAG)
		g_manager.syntax_error = false;
	return (ast);
}
