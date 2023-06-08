/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:06:49 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:41:24 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager	g_manager;

static void	reset_minishell(t_ast *ast, int std_fd[3])
{
	free_ast(ast);
	reset_std_fd(std_fd);
}

/**
 * Initializes the g_manager structure with the provided command line argument, as well as default values for the rc and quote_error fields. rc: An integer value that keeps track of the number of characters read. quote_error: A integer value that indicates whether an error occurred due to mismatched quotes in the command line.
 * @param command_line A pointer to a character array that represents the command line passed to the program. This parameter is used to initialize the command_line field of the g_manager structure.
*/
static void	init_manager(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
	g_manager.quote_error = 0;
}

/**
 * Initialize the shell program by setting up the environment variables and backing up the standard file descriptors. If the environment variable OLDPWD exists, the function frees its value and sets it to NULL.
 * @param argc An integer representing the number of command line arguments.
 * @param argv A pointer to an array of strings representing the command line arguments.
 * @param envp A pointer to an array of strings representing the environment variables.
 * @param std_fd An integer array representing the file descriptors for standard input, output and error.
*/
static void	init_minishell(int argc, char **argv, char **envp, int std_fd[3])
{
	t_env	*oldpwd;

	if (argc > 1)
		throw_error_exit(argv[1], strerror(ENOENT), EXIT_ENOENT);
	backup_std_fd(std_fd);
	while (*envp)
	{
		add_env(get_env_name(*envp), get_env_value(*envp));
		envp++;
	}
	oldpwd = get_env("OLDPWD");
	if (oldpwd)
	{
		if (oldpwd->value)
			free(oldpwd->value);
		oldpwd->value = NULL;
	}
}

void	print_ast(t_ast *ast)
{
	t_ast *tmp;
	tmp = ast;
	if (tmp == NULL)
		return ;
	if (tmp->type == AST_PIPELINE)
	{
		printf("Pipe->\n");
		t_pipe_line *tmp_pipe_line = tmp->data;
		print_ast(tmp_pipe_line->command);
	}
	else if (tmp->type == AST_COMMAND)
	{
		printf("Command->\n");
		t_command *tmp_command = tmp->data;
		print_ast(tmp_command->redirects);
		print_ast(tmp_command->pipe_line);
	}
	else if (tmp->type == AST_REDIRECTS)
	{
		printf("Redirect->\n");
		t_redirects *tmp_redirects = tmp->data;
		print_ast(tmp_redirects->redirects);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int				std_fd[3];
	char			*command_line;
	t_ast			*ast;

	init_minishell(argc, argv, envp, std_fd);
	while (true)
	{
		init_signal();
		command_line = readline(PS1);
		sh_exit_eof(command_line);
		if (command_line && *command_line)
		{
			add_history(command_line);
			init_manager(command_line);
			ast = syntax_analyzer();
			print_ast(ast);
			// if (ast && g_manager.exit_code == EXIT_SUCCESS)
			// 	exec_command_line(&ast);
			// else if (fetch_token(GET).value)
			// 	free(fetch_token(GET).value);
			reset_minishell(ast, std_fd);
		}
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
