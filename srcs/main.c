/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:06:49 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 13:19:29 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager	g_manager;

static void	reset_minishell(t_ast *ast, int std_fd[3])
{
	free_ast(ast);
	free(g_manager.token.value);
	reset_std_fd(std_fd);
}

/**
 * Initializes the g_manager structure with the provided command line argument, 
 * as well as default values for the rc and quote_error fields. rc: An integer 
 * value that keeps track of the number of characters read. quote_error: A 
 * integer value that indicates whether an error occurred due to mismatched 
 * quotes in the command line.
 * @param command_line A pointer to a character array that represents the 
 * command line passed to the program. This parameter is used to initialize the 
 * command_line field of the g_manager structure.
*/
static void	init_manager(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
	g_manager.quote_error = 0;
}

void free_manager() {
	free(g_manager.token.value);
	free_ast(g_manager.ast);
	free_env(g_manager.env);
}

/**
 * Initialize the shell program by setting up the environment variables and 
 * backing up the standard file descriptors.
 * @param argc An integer representing the number of command line arguments.
 * @param argv A pointer to an array of strings representing the command line 
 * arguments.
 * @param envp A pointer to an array of strings representing the environment 
 * variables.
 * @param std_fd An integer array representing the file descriptors for 
 * standard input, output and error.
*/
static void	init_minishell(int argc, char **argv, char **envp, int std_fd[3])
{
	if (argc > 1)
		throw_error_exit(argv[1], strerror(ENOENT), EXIT_ENOENT);
	backup_std_fd(std_fd);
	while (*envp)
	{
		add_env(get_env_name(*envp), get_env_value(*envp));
		envp++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int				std_fd[3];
	char			*command_line;

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
			g_manager.ast = syntax_analyzer();
			if (g_manager.ast && g_manager.exit_code == EXIT_SUCCESS)
				exec_command_line(&g_manager.ast);
			reset_minishell(g_manager.ast, std_fd);
		}
		free(command_line);
	}
	return (EXIT_SUCCESS);
}
