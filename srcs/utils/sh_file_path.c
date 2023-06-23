/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_file_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:00 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 13:11:53 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Takes a pointer to a null-terminated array of strings (i.e., an array of 
 * pointers to characters) and frees all the memory allocated for it.
 * @param path A pointer to a null-terminated array of strings.
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
 * Splits the PATH environment variable into an array of strings. If the PATH 
 * environment variable exists, it is split by the delimiter ":" using the 
 * ft_split() function from the library. Otherwise, it creates an array with a 
 * single element containing the current directory ("."). The function returns 
 * the resulting array of strings.
 * @return A pointer to a char pointer representing the array of strings 
 * created by splitting the PATH environment variable.
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
 * Searches for the given command in the directories listed in the PATH 
 * environment variable. If the command is found, the full path to the 
 * executable is returned. If the command is not found in any of the 
 * directories, the function returns the original command.
 * @param cmd A string representing the command to search for in the 
 * directories.
 * @return A string representing the full path to the executable if found, or 
 * the original command if not found.
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
	return (ft_strdup(cmd));
}
