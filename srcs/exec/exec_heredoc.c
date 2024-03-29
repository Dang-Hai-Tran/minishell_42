/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:15:57 by datran            #+#    #+#             */
/*   Updated: 2023/07/22 23:16:03 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Generates a unique file path for a heredoc by concatenating a temporary
 * directory and a count to a base string.
 *
 * @return The generated file path.
 */
char	*create_heredoc_path(void)
{
	static unsigned int	cnt;
	char				*cnt_arr;
	char				*heredoc_path;
	char				*tmpdir;

	if (get_env(TMPENV) == NULL)
		tmpdir = ft_strjoin(TMPDIR, TMPKEY);
	else
		tmpdir = ft_strjoin(get_env(TMPENV)->value, TMPKEY);
	cnt_arr = ft_itoa(cnt);
	heredoc_path = ft_strjoin(tmpdir, cnt_arr);
	free(tmpdir);
	free(cnt_arr);
	cnt++;
	return (heredoc_path);
}

/**
 * Executes a redirection to a heredoc by creating a new file path for the
 * heredoc and redirecting the input to the heredoc.
 *
 * @param ast Double pointer to a t_ast object representing the redirections.
 *
 * @return A flag indicating success if the heredoc is executed successfully
 * 	otherwise returns an error flag.
 */
static int	exec_redirect_heredoc(t_ast **ast)
{
	int				flag;
	t_token			token;
	t_redirects		*redirects;
	t_io_redirect	*io_redirect;

	token.type = T_NULL;
	token.value = NULL;
	flag = SUCCESS_FLAG;
	redirects = NULL;
	io_redirect = NULL;
	if (*ast && (*ast)->type == AST_REDIRECTS)
		redirects = (*ast)->data;
	if (redirects && redirects->io_redirect)
		io_redirect = redirects->io_redirect;
	if (io_redirect->redirect_op == R_HEREDOC)
	{
		if (io_redirect->end_text == NULL)
			return (throw_error_syntax(token));
		io_redirect->file_path = create_heredoc_path();
		flag |= redirect_heredoc(io_redirect->end_text, io_redirect->file_path);
	}
	if (redirects->redirects)
		flag |= exec_redirect_heredoc(&redirects->redirects);
	return (flag);
}

/**
 * Executes all heredocs in a command line represented as an AST. It executes
 * the heredoc for each command and pipeline in the AST.
 *
 * @param ast Double pointer to a t_ast object representing the command line.
 *
 * @return A flag indicating success if all heredocs are executed successfully,
 * 	otherwise returns an error flag.
 */
int	exec_heredoc(t_ast **ast)
{
	int				flag;
	t_pipe_line		*pipe_line;
	t_command		*command;

	flag = SUCCESS_FLAG;
	pipe_line = NULL;
	command = NULL;
	if (*ast && (*ast)->type == AST_PIPELINE)
		pipe_line = (*ast)->data;
	if (pipe_line && pipe_line->command->type == AST_COMMAND)
		command = pipe_line->command->data;
	if (command && command->redirects)
		flag |= exec_redirect_heredoc(&command->redirects);
	if (flag == ERROR_FLAG)
		return (ERROR_FLAG);
	if (pipe_line && pipe_line->pipe_line)
		flag |= exec_heredoc(&pipe_line->pipe_line);
	return (flag);
}
