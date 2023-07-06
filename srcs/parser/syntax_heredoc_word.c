/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_heredoc_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:18:29 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:10:04 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extracts the word for a heredoc redirection. If the first character of
 * the token is a quote, it extracts the substring between the quotes.
 * Otherwise, it duplicates the token.
 *
 * @param token The token from which to extract the word.
 *
 * @return The extracted word.
 */
char	*syntax_heredoc_word(char *token)
{
	char	*word;

	if (*token == U_DOUBLE_QUOTES || *token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = ft_strdup(token);
	free(token);
	return (word);
}
