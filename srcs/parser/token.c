/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:31:04 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:48:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Retrieve each token in the input stream.
 * @return A t_token struct that contains information about the current token 
 * in the input stream. If an error occurs during lexical analysis, the 
 * function sets the exit code to EXIT_SYNTAXERR.
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
	if (!ft_strlcpy(token.value, begin, end - begin + 1))
		return (token);
	g_manager.rc += end - begin;
	return (token);
}

/**
 * Retrieving the next token from the input stream and returning it to the 
 * caller. It can be used to either get the current token or to update the 
 * token stream with the next token.
 * @param type An enum value of type t_fetch_type determines whether the 
 * function should return the current token or fetch the next token from the 
 * input stream.
 * @return A t_token struct that represents the current token in the input 
 * stream if the type parameter is GET. If the type parameter is UPDATE, the 
 * function update the token stream with the next token and return this token.
*/
t_token	fetch_token(t_fetch_type type)
{
	if (type == GET)
		return (g_manager.token);
	else if (type == UPDATE)
		g_manager.token = get_token();
	return (g_manager.token);
}
