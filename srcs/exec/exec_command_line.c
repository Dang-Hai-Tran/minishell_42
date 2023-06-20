/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:14:53 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 13:30:01 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Checks for input/output redirects and redirects that modify file descriptors in the redirect structure and then executes them accordingly.
 * @param redirects A pointer to a t_redirects structure that contains the redirects to be executed
 * @return Returns an integer value indicating the success or failure of the execution
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
 * Executes the given command based on the type of command. It checks for redirects and simple commands in the command structure and then executes them accordingly.
 * @param command A pointer to a t_command structure that contains the command to be executed
 * @return Returns an integer value indicating the success or failure of the execution
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
 * Execute a single pipeline command or a subshell. The function takes a pointer to a t_pipe_line struct as input, which contains information about the command to be executed. If the t_pipe_line struct contains a subshell, the function calls the exec_subshell function to execute the subshell. If the t_pipe_line struct contains a single command, the function calls the exec_single_command function to execute the command. The function returns an integer value representing the exit status of the command.
 * @param pipe_line A pointer to a t_pipe_line struct containing information about the command to be executed
 * @return An integer value representing the exit status of the command. If the command is executed successfully, the function returns SUCCESS_FLAG. If there is an error during execution, the function returns ERROR_FLAG
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
 * Execute a command or pipeline represented by an abstract syntax tree (AST).
 * @param ast A pointer to an AST node representing a command or pipeline to be executed
 * @return an integer value representing the exit status of the command or pipeline. If the command or pipeline is executed successfully, the function returns SUCCESS_FLAG. If there is an error during execution, the function returns ERROR_FLAG
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
 * Execute a command line. The function takes a pointer to a pointer to an ast struct as input, which contains information about the command line to be executed. The function first checks for any here documents in the command line and executes them using the exec_heredoc function. If there are no here documents or they are executed successfully, the function calls the exec_ast function to execute the commands in the command line. The function returns an integer value representing the exit status of the command line.
 * @param ast A pointer to a pointer to an ast struct containing information about the command line to be executed
 * @return An integer value representing the exit status of the command line. If the command line is executed successfully, the function returns SUCCESS_FLAG. If there is an error during execution, the function returns ERROR_FLAG
*/
int	exec_command_line(t_ast **ast)
{
	if (exec_heredoc(ast))
		return (ERROR_FLAG);
	if (exec_ast(*ast))
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
