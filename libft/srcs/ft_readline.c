/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:46 by datran            #+#    #+#             */
/*   Updated: 2023/07/23 11:17:18 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *file_content)
{
	int		i;
	char	*s;

	i = 0;
	if (!file_content[i])
		return (NULL);
	while (file_content[i] && file_content[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (file_content[i] && file_content[i] != '\n')
	{
		s[i] = file_content[i];
		i++;
	}
	if (file_content[i] == '\n')
	{
		s[i] = file_content[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

static char	*ft_read_file(int fd, char *file_content)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr_gnl(file_content, '\n') && read_bytes > 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		file_content = ft_strjoin_gnl(file_content, buff);
	}
	free(buff);
	return (file_content);
}

char	*ft_readline(int fd)
{
	char		*line;
	char		*file_content;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	file_content = NULL;
	file_content = ft_read_file(fd, file_content);
	if (!file_content)
		return (NULL);
	line = ft_get_line(file_content);
	free(file_content);
	return (line);
}
