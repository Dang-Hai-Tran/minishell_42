/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_heredoc_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 00:18:29 by datran            #+#    #+#             */
/*   Updated: 2023/06/26 15:47:37 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
