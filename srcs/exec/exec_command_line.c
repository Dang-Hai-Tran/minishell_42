/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:14:53 by datran            #+#    #+#             */
/*   Updated: 2023/07/23 01:41:58 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Executes the redirections in a given t_redirects object by executing the
 * IO redirections and AST redirections if they are present.
 *
 * @param redirects Pointer to a t_redirects object containing the redirections
 * 	to execute.
 *
 * @return A flag indicating success if all redirections are executed
 * 	successfully, otherwise returns an error flag.
 */
int	exec_redirects(t_redirects *redirects)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (redirects->io_redirect)
		flag = exec_io_redirect(redirects->io_redirect);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (redirects->redirects)
		flag = exec_ast(redirects->redirects);
	return (flag);
}

/**
 * Executes a command stored in a t_command object by executing the
 * command's redirects and simple command if they are present.
 *
 * @param command Pointer to a t_command object containing the command to
 * 	execute.
 *
 * @return A flag indicating success if all components of the command are
 * 	executed successfully, otherwise returns an error flag.
 */
int	exec_command(t_command *command)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (command->redirects)
		flag = exec_ast(command->redirects);
	if (flag != SUCCESS_FLAG)
		return (ERROR_FLAG);
	if (command->simple_command)
		flag = exec_simple_command(command->simple_command);
	return (flag);
}

/**
 * Executes a pipeline stored in a t_pipe_line object by executing a subshell
 * or a single command based on the type of the pipeline.
 *
 * @param pipe_line Pointer to a t_pipe_line object containing the pipeline to
 * 	execute.
 *
 * @return A flag indicating success if the pipeline is executed successfully,
 * 	otherwise returns an error flag.
 */
int	exec_pipe_line(t_pipe_line *pipe_line)
{
	int	flag;

	flag = SUCCESS_FLAG;
	if (pipe_line->pipe_line)
		flag = exec_subshell(pipe_line);
	else if (pipe_line->command && pipe_line->command->type == AST_COMMAND)
		flag = exec_single_command(pipe_line->command->data);
	else
		flag = ERROR_FLAG;
	return (flag);
}

/**
 * Executes an abstract syntax tree (AST) by executing a pipeline, a command,
 * or redirects based on the type of the AST.
 *
 * @param ast Pointer to a t_ast object representing the abstract syntax tree
 * 	to execute.
 *
 * @return A flag indicating success if the AST is executed successfully,
 * 	otherwise returns an error flag.
 */
int	exec_ast(t_ast *ast)
{
	if (ast->type == AST_PIPELINE)
		return (exec_pipe_line(ast->data));
	else if (ast->type == AST_COMMAND)
		return (exec_command(ast->data));
	else if (ast->type == AST_REDIRECTS)
		return (exec_redirects(ast->data));
	else
		return (ERROR_FLAG);
}

/**
 * Executes a command line represented as an AST. It starts by executing 
 * heredoc if it exists, then it executes the AST.
 *
 * @param ast Double pointer to a t_ast object representing the command
 * 	line to execute.
 *
 * @return A flag indicating success if the command line is executed
 * 	successfully, otherwise returns an error flag.
 */
int	exec_command_line(t_ast **ast)
{
	if (exec_heredoc(ast))
		return (ERROR_FLAG);
	if (exec_ast(*ast))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
