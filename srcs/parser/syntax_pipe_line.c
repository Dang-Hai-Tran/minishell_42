/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_pipe_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:04:26 by datran            #+#    #+#             */
/*   Updated: 2023/06/11 21:16:33 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Initializes a new t_ast struct for a pipeline in the input stream. It 
 * allocates memory for the struct and its associated t_pipe_line data, and 
 * sets the type of the t_ast struct to AST_PIPELINE.
 * @param ast_pipe_line A pointer to a pointer to a t_ast struct that will be 
 * updated with information about the current pipeline in the input stream. The 
 * ast_pipe_line pointer will be updated to point to the root node of the 
 * pipeline AST.
*/
static void	init_syntax_pipe_line(t_ast **ast_pipe_line)
{
	*ast_pipe_line = ft_calloc(1, sizeof(t_ast));
	(*ast_pipe_line)->type = AST_PIPELINE;
	(*ast_pipe_line)->data = ft_calloc(1, sizeof(t_pipe_line));
}

/**
 * Constructs an abstract syntax tree (AST) for the pipeline and returns a 
 * success or error flag based on whether the pipeline was parsed successfully.
 * @param ast_pipe_line A pointer to a pointer to a t_ast struct that will be 
 * updated with information about the current pipeline in the input stream. The 
 * ast_pipe_line pointer will be updated to point to the root node of the 
 * pipeline AST.
 * @return An integer value indicating whether the pipeline was parsed 
 * successfully or not. It returns SUCCESS_FLAG if the pipeline was parsed 
 * successfully, and ERROR_FLAG if an error occurred during parsing.
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
