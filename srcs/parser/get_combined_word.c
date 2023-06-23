/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_combined_word.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:26:35 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 09:24:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
 * Combines multiple words into a single string, by iterating through the input 
 * and concatenating each word together.
 * @return A pointer to a newly allocated string containing the combined words. 
 * If an error occurs or no words are found, it returns NULL.
*/
char	*get_combined_word(void)
{
	char	*combined_word;
	char	*token;
	char	*word;
	char	*tmp;
	char	next;

	next = g_manager.command_line[g_manager.rc];
	token = match(T_WORD);
	if (!token)
		return (NULL);
	combined_word = syntax_word(token);
	while (!ft_isspace(next) && fetch_token(GET).type == T_WORD)
	{
		next = g_manager.command_line[g_manager.rc];
		word = syntax_word(match(T_WORD));
		tmp = combined_word;
		combined_word = ft_strjoin(combined_word, word);
		free(word);
		free(tmp);
	}
	return (combined_word);
}
