/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_putline_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:55:31 by datran            #+#    #+#             */
/*   Updated: 2023/07/23 11:21:51 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Gets the first word from a line string.
 *
 * @param line The line string.
 * @return Returns the first word in the line.
 */
static char	*get_word(char *line)
{
	int		len;
	char	*word;

	len = 0;
	while (line[len] && !ft_isspace(line[len]))
		len++;
	word = ft_substr(line, 0, len);
	return (word);
}

/**
 * Writes a line to a file descriptor, replacing any environment
 * variables with their corresponding values.
 *
 * @param line The line to write.
 * @param fd The file descriptor to write to.
 */
void	sh_putline_heredoc(char *line, int fd)
{
	char	*word;
	char	*tmp;

	while (*line)
	{
		if (ft_isspace(*line))
		{
			ft_putchar_fd(*line, fd);
			line++;
		}
		else
		{
			word = get_word(line);
			tmp = word;
			word = replace_env(word);
			ft_putstr_fd(word, fd);
			line += ft_strlen(tmp);
			free(tmp);
			free(word);
		}
	}
}
