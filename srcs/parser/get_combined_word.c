/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_combined_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:26:35 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 17:25:30 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Combines the heredoc word tokens into a single string.
 *
 * @return A pointer to a combined heredoc word string.
 * If there are no word tokens, it will return NULL.
 */
char	*get_combined_heredoc_word(void)
{
	char	*combined_word;
	char	*word;
	char	*tmp;
	char	*token;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	combined_word = syntax_heredoc_word(token);
	while (!ft_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_heredoc_word(match(T_WORD));
		tmp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(tmp);
	}
	return (combined_word);
}

/**
 * Combines the word tokens into a single string.
 *
 * @return A pointer to a combined word string.
 * 	If there are no word tokens, it will return NULL.
 */
char	*get_combined_word(void)
{
	char	*cb_word;
	char	*token;
	char	*word;
	char	*tmp;
	char	*next;

	next = &g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	cb_word = syntax_word(token);
	if (ft_strchr("\"\'", *next) && *(next - 1) == '$' && *(next - 2) != '$')
		ft_strlcpy(cb_word, cb_word, ft_strlen(cb_word));
	while (!ft_isspace(*next) && fetch_token(GET).type == T_WORD)
	{
		next = &g_manager.command_line[g_manager.rc];
		if (ft_strchr("\"\'", *next) && *(next - 1) == '$' && *(next - 2) != '$')
			ft_strlcpy(cb_word, cb_word, ft_strlen(cb_word));
		word = syntax_word(match(T_WORD));
		tmp = cb_word;
		cb_word = ft_strjoin(cb_word, word);
		free(word);
		free(tmp);
	}
	return (cb_word);
}
