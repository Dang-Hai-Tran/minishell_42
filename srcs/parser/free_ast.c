/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:10:28 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 12:24:54 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_redirects(t_redirects *redirects)
{
	if (redirects->io_redirect)
		free_io_redirect(redirects->io_redirect);
	if (redirects->redirects)
		free_ast(redirects->redirects);
	free(redirects);
}

void	free_command(t_command *command)
{
	if (command->simple_command)
		free_simple_command(command->simple_command);
	if (command->redirects)
		free_ast(command->redirects);
	free(command);
}
/**
 * Free the memory allocated for a pipeline data structure created by a shell.
 * @param pipe_line A pointer to the pipeline data structure that needs to be freed
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
 * Free the memory allocated for an abstract syntax tree (AST) created by a shell.
 * @param ast A pointer to the root node of the abstract syntax tree that needs to be freed.
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
