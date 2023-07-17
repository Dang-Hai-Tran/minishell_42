/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_file_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:00 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 19:53:35 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Frees an array of strings.
 *
 * @param path The array of strings to free.
 */
static void	free_path(char **path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		free(path[i]);
		i++;
	}
	free(path);
}

/**
 * Splits the PATH environment variable into an array of paths.
 *
 * @return Returns an array of paths.
 */
static char	**split_path(void)
{
	char	**path;

	if (get_env(PATHENV))
		path = ft_split(get_env(PATHENV)->value, ':');
	else
	{
		path = (char **)ft_calloc(2, sizeof(char *));
		*path = ft_strdup(".");
	}
	return (path);
}

/**
 * Searches for a command in the PATH environment variable.
 * It checks each path in the PATH until it finds the command,
 * or it has checked all paths.
 *
 * @param cmd The command to search for.
 * @return Returns the full path of the command if it's found,
 * 	otherwise returns the command itself.
 */
char	*sh_find_path(char *cmd)
{
	char		**path;
	char		*filename;
	char		*tmp;
	int			i;

	i = 0;
	path = split_path();
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		filename = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(filename, F_OK) == 0)
			return (filename);
		free(filename);
		i++;
	}
	free_path(path);
	return (NULL);
}
