/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_file_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:00 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 14:59:00 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*sh_find_path(char *cmd)
{
	struct stat	buf;
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
		if (stat(filename, &buf) != -1)
			return (filename);
		free(filename);
		i++;
	}
	free_path(path);
	return (ft_strdup(cmd));
}
