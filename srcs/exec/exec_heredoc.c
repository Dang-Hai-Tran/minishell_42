/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_heredoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:15:57 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 13:59:41 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Create a path for the here-document file. The function generates a unique path by appending a counter at the end of the temporary directory path.
 * @return A pointer to a string that contains the path for the here-document file
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
 * Execute the redirection of a here-document. The function checks if an input/output redirection node in the abstract syntax tree contains a here-document and creates a file to store the here-document contents.
 * @param ast A double pointer to the current node in the abstract syntax tree
 * @return An integer value that represents the success or failure of the redirection operation

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
 * Execute the heredoc redirection for a given abstract syntax tree (AST).
 * @param ast A double pointer to the AST that needs to be executed
 * @return A flag which indicates the success or failure of the heredoc redirection execution. If the execution is successful, the flag will have a value of SUCCESS_FLAG. If there is any error during the execution, the flag will have a value of ERROR_FLAG.
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
