/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyzer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 19:03:34 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 13:53:44 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Matches the next token in the input string with a given type, and returns 
 * the value of that token if it matches. If the token does not match, it 
 * throws a syntax error.
 * @param type An enum representing the type of token to match against.
 * @return A pointer to a string representing the value of the matched token, 
 * if the token type matches the input parameter. If the token type does not 
 * match, it throws a syntax error and returns NULL.
*/
char	*match(t_type type)
{
	t_token	token;

	token = fetch_token(UPDATE);
	if (token.type == type)
		return (token.value);
	else
		throw_error_syntax(token);
	return (NULL);
}

/**
 * Fetches the first token from the input and then calls the syntax_pipe_line function to parse the rest of the input into an abstract syntax tree (AST).
 * @return A pointer to the root node of the AST that represents the parsed input, or NULL if there was an error during parsing.
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
	if (syntax_pipe_line(&ast) == SUCCESS_FLAG
		&& g_manager.quote_error == SUCCESS_FLAG)
		g_manager.exit_code = EXIT_SUCCESS;
	return (ast);
}
