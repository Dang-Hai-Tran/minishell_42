/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:22 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 10:00:20 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Retrieves a word from the input stream and updates a t_token struct with information about the word.
 * @param token A pointer to a t_token struct that will be updated with 
 * information about the current token in the input stream.
 * @param end A pointer to a pointer that points to the current position in the 
 * input stream. The end pointer will be updated to point to the end of the 
 * current token.
*/
static void	get_word(t_token *token, char **end)
{
	token->type = T_WORD;
	while (**end && (!ft_isspace(**end)) && !ft_strchr("<>|\"'", **end))
		(*end)++;
}
/**
 * Retrieves a quoted string from the input stream and updates a t_token struct 
 * with information about the string.
 * @param token A pointer to a t_token struct that will be updated with 
 * information about the current token in the input stream.
 * @param end A pointer to a pointer that points to the current position in the 
 * input stream. The end pointer will be updated to point to the end of the 
 * current token.
*/
static void	get_quote(t_token *token, char **end)
{
	token->type = T_WORD;
	*end = ft_strchr(*end + 1, **end);
	if (!*end)
	{
		throw_error("syntax error", NULL, "unexpected end of file");
		*end = g_manager.command_line + ft_strlen(g_manager.command_line);
		g_manager.quote_error = 1;
	}
	else
		(*end)++;
}
/**
 * Retrieves a pipe character from the input stream and updates a t_token 
 * struct with information about the character.
 * @param token A pointer to a t_token struct that will be updated with 
 * information about the current token in the input stream.
 * @param end A pointer to a pointer that points to the current position in the 
 * input stream. The end pointer will be updated to point to the character 
 * immediately after the pipe character.
*/
static void	get_pipe(t_token *token, char **end)
{
	token->type = T_PIPE;
	(*end)++;
}
/**
 * Retrieves a redirection operator from the input stream and updates a t_token 
 * struct with information about the operator.
 * @param token A pointer to a t_token struct that will be updated with information about the current token in the input stream.
 * @param end A pointer to a pointer that points to the current position in the input stream. The end pointer will be updated to point to the character immediately after the redirection operator.
*/
static void	get_redirect_op(t_token *token, char **end)
{
	token->type = T_REDIRECT;
	if (**end == U_IN && *(*end + 1) == U_IN)
		*end += 2;
	else if (**end == U_OUT && *(*end + 1) == U_OUT)
		*end += 2;
	else if (**end == U_IN)
		(*end)++;
	else if (**end == U_OUT)
		(*end)++;
}

/**
 * Identifying the type of the current token in the input stream and setting 
 * the appropriate values in a t_token struct.
 * @return An integer flag indicating whether the lexical analysis was 
 * successful or not. If the function encounters an error during lexical 
 * analysis, it returns ERROR_FLAG. Otherwise, it returns SUCCESS_FLAG.
*/
int	lexical_analyzer(t_token *token, char **begin, char **end)
{
	while (ft_isspace(g_manager.command_line[g_manager.rc]))
		g_manager.rc++;
	*begin = &g_manager.command_line[g_manager.rc];
	*end = *begin;
	if (g_manager.rc >= (int)ft_strlen(g_manager.command_line))
		return (ERROR_FLAG);
	if ((**begin == U_DOUBLE_QUOTES || **begin == U_SINGLE_QUOTES))
		get_quote(token, end);
	else if (**begin == U_IN || **begin == U_OUT)
		get_redirect_op(token, end);
	else if (**begin == U_PIPE)
		get_pipe(token, end);
	else
		get_word(token, end);
	if (g_manager.quote_error)
		return (ERROR_FLAG);
	else
		return (SUCCESS_FLAG);
}
