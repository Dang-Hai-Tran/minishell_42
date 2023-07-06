/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:04:26 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 23:26:17 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initializes a new syntax pipe line. It allocates memory for the AST pipe line node 
 * and sets the node type to AST_PIPELINE. It also allocates memory for the pipe line data.
 *
 * @param ast_pipe_line Pointer to the AST pipe line node to be initialized.
 */
static void	init_syntax_pipe_line(t_ast **ast_pipe_line)
{
	*ast_pipe_line = ft_calloc(1, sizeof(t_ast));
	(*ast_pipe_line)->type = AST_PIPELINE;
	(*ast_pipe_line)->data = ft_calloc(1, sizeof(t_pipe_line));
}

/**
 * Parses a pipe line. It fetches a token and checks its type. If the token type is not T_WORD or T_REDIRECT,
 * it throws a syntax error. Otherwise, it initializes a pipe line node, parses a command and, if the next token
 * type is T_PIPE, it parses a pipe line. If any of these steps fail, it returns an error flag.
 *
 * @param ast_pipe_line Pointer to the AST pipe line node.
 *
 * @return SUCCESS_FLAG if the parsing is successful, ERROR_FLAG otherwise.
 */
int	syntax_pipe_line(t_ast **ast_pipe_line)
{
	t_pipe_line	*pipe_line;
	t_token		token;
	char		*pipe;

	token = fetch_token(GET);
	if (!(token.type == T_WORD || token.type == T_REDIRECT))
		return (throw_error_syntax(token));
	init_syntax_pipe_line(ast_pipe_line);
	pipe_line = (*ast_pipe_line)->data;
	if (syntax_command(&pipe_line->command))
		return (ERROR_FLAG);
	if (fetch_token(GET).type == T_PIPE)
	{
		pipe = match(T_PIPE);
		if (pipe == NULL)
			return (ERROR_FLAG);
		free(pipe);
		if (syntax_pipe_line(&pipe_line->pipe_line))
			return (ERROR_FLAG);
	}
	return (SUCCESS_FLAG);
}
