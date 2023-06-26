/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_putline_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:55:31 by datran            #+#    #+#             */
/*   Updated: 2023/06/26 16:54:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	ft_putchar_fd('\n', fd);
}
