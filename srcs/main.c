/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:06:49 by datran            #+#    #+#             */
/*   Updated: 2023/07/15 00:37:32 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_manager	g_manager;

/**
 * Frees resources related to a command execution cycle.
 * Frees abstract syntax tree (AST), token value and resets the standard file
 * descriptors.
 *
 * @param ast The abstract syntax tree to free.
 * @param std_fd The standard file descriptors to reset.
 */
static void	reset_minishell(t_ast *ast, int std_fd[3])
{
	free_ast(ast);
	free(g_manager.token.value);
	reset_std_fd(std_fd);
}

/**
 * Initializes the global manager object. Resets command line, return code
 * and quote error flag.
 *
 * @param command_line The command line string.
 */
static void	init_manager(char *command_line)
{
	g_manager.command_line = command_line;
	g_manager.rc = 0;
	g_manager.quote_error = 0;
}

/**
 * Frees the resources held by the global manager object.
 * Frees token value, abstract syntax tree (AST) and environment variables list
 */
void	free_manager(void)
{
	free(g_manager.token.value);
	free_ast(g_manager.ast);
	free_env(g_manager.env);
}

/**
 * Initializes the shell environment. Backups standard file descriptors,
 * parses environment variables and throws an error if the shell is run
 * with more than one argument.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param envp The environment variables array.
 * @param std_fd The standard file descriptors to backup.
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

/**
 * The entry point for the minishell program. Initializes the shell environment
 * reads commands from the user, parses the commands, executes the commands,
 * and then cleans up the resources. The shell runs in a continuous 
 * loop until the user exits.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @param envp The environment variables array.
 * @return Returns EXIT_SUCCESS when the shell exits successfully.
 */
int	main(int argc, char **argv, char **envp)
{
	int				std_fd[3];
	char			*command_line;

	init_minishell(argc, argv, envp, std_fd);
	while (true)
	{
		init_signal();
		if (isatty(fileno(stdin)))
			command_line = readline(PS1);
		else
		{
			char *line;
			line = ft_gnl(fileno(stdin));
			command_line = ft_strtrim(line, "\n");
			free(line);
		}
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
