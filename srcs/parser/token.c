/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:31:04 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 11:37:11 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Fetches the next token from the command line stored in the global manager.
 * It passes the token to the lexical analyzer which determines its type and 
 * value, and also identifies the begin and end positions of the token in the
 * command line.
 *
 * @return The fetched token.
 */
t_token	get_token(void)
{
	char	*begin;
	char	*end;
	t_token	token;
	int		flag;

	token.type = T_NULL;
	token.value = NULL;
	flag = lexical_analyzer(&token, &begin, &end);
	if (g_manager.rc >= (int)ft_strlen(g_manager.command_line))
		return (token);
	if (flag == ERROR_FLAG)
		g_manager.exit_code = EXIT_SYNTAXERR;
	token.value = ft_calloc(end - begin + 1, sizeof(char));
	if (!token.value)
		return (token);
	ft_strlcpy(token.value, begin, end - begin + 1);
	g_manager.rc += end - begin;
	return (token);
}

/**
 * Fetches a token based on the fetch type. If the type is GET, it returns
 * the current token stored in the global manager. If the type is UPDATE,
 * it fetches the next token and updates the current token 
 * stored in the global manager.
 *
 * @param type The type of fetch operation to perform, either GET or UPDATE.
 *
 * @return The fetched token.
 */
t_token	fetch_token(t_fetch_type type)
{
	if (type == GET)
		return (g_manager.token);
	else if (type == UPDATE)
		g_manager.token = get_token();
	return (g_manager.token);
}
