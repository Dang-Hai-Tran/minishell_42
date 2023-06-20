/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 16:47:37 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 13:34:54 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_count(void)
{
	t_env	*ptr;
	int		count;

	ptr = g_manager.env;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

static char	**get_string_env(void)
{
	t_env	*ptr;
	char	**ret;
	char	*tmp;
	int		count;
	int		i;

	ptr = g_manager.env;
	count = get_count();
	ret = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr && ptr->value)
	{
		tmp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(tmp, ptr->value);
		free(tmp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}
static int	error_execve(char *argv)
{
	int	exit_code;

	exit_code = EXIT_FAILURE;
	if (errno == ENOENT)
	{
		exit_code = EXIT_ENOENT;
		throw_error(argv, NULL, "command not found");
	}
	else if (errno == EACCES)
	{
		exit_code = EXIT_EACCES;
		throw_error(argv, NULL, strerror(errno));
	}
	return (exit_code);
}

/**
 * Executes the given command. It checks if the command is present in the system path or not, and then executes it using the execve() system call.
 * @param argv A pointer to a char array that contains the command and its arguments
 * @return An integer value indicating the success or failure of the execution
*/
int	exec_general(char **argv)
{
	char	**envp;
	char	*filename;

	envp = get_string_env();
	if (ft_strchr(*argv, '/') == NULL)
	{
		if (get_env(PATHENV))
			filename = sh_find_path(*argv);
	}
	else
		filename = ft_strdup(*argv);
	if (!argv[0][0])
		throw_error_exit(argv[0], "command not found", EXIT_ENOENT);
	execve(filename, argv, envp);
	free(filename);
	return (error_execve(*argv));
}
