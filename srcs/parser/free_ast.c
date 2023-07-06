/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:10:28 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Frees the memory allocated for a `t_redirects` structure.
 *
 * @param redirects Pointer to a `t_redirects` structure to be freed.
 */
void	free_redirects(t_redirects *redirects)
{
	if (redirects->io_redirect)
		free_io_redirect(redirects->io_redirect);
	if (redirects->redirects)
		free_ast(redirects->redirects);
	free(redirects);
}

/**
 * Frees the memory allocated for a `t_command` structure.
 *
 * @param command Pointer to a `t_command` structure to be freed.
 */
void	free_command(t_command *command)
{
	if (command->simple_command)
		free_simple_command(command->simple_command);
	if (command->redirects)
		free_ast(command->redirects);
	free(command);
}

/**
 * Frees the memory allocated for a `t_pipe_line` structure.
 *
 * @param pipe_line Pointer to a `t_pipe_line` structure to be freed.
 */
void	free_pipe_line(t_pipe_line *pipe_line)
{
	if (pipe_line->command)
		free_ast(pipe_line->command);
	if (pipe_line->pipe_line)
		free_ast(pipe_line->pipe_line);
	free(pipe_line);
}

/**
 * Frees the memory allocated for a `t_ast` structure.
 *
 * @param ast Pointer to a `t_ast` structure to be freed.
 */
void	free_ast(t_ast *ast)
{
	if (ast == AST_NULL)
		return ;
	if (ast->type == AST_PIPELINE)
		free_pipe_line(ast->data);
	else if (ast->type == AST_COMMAND)
		free_command(ast->data);
	else if (ast->type == AST_REDIRECTS)
		free_redirects(ast->data);
	free(ast);
}
