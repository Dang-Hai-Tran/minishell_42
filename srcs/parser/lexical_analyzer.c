/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexical_analyzer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:22 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:19:53 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Processes the command line to get a word token. It moves the `end
 * pointer to the end of the word token.
 *
 * @param token Pointer to a `t_token` structure where the word token
 * will be stored.
 * @param end Pointer to a char pointer that points to the end of the
 * token in the command line string.
 */
static void	get_word(t_token *token, char **end)
{
	token->type = T_WORD;
	while (**end && (!ft_isspace(**end)) && !ft_strchr("<>|\"\'", **end))
		(*end)++;
}

/**
 * Processes the command line to get a quoted token. It moves the `end`
 * pointer to the end of the quoted token.
 *
 * @param token Pointer to a `t_token` structure where the quoted
 * 	token will be stored.
 * @param end Pointer to a char pointer that points to the end of
 * 	the token in the command line string.
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
 * Processes the command line to get a pipe token. It moves the
 * `end` pointer to the end of the pipe token.
 *
 * @param token Pointer to a `t_token` structure where the pipe
 * 	token will be stored.
 * @param end Pointer to a char pointer that points to the end
 * 	of the token in the command line string.
 */
static void	get_pipe(t_token *token, char **end)
{
	token->type = T_PIPE;
	(*end)++;
}

/**
 * Processes the command line to get a redirect operator token.
 * It moves the `end` pointer to the end of the redirect operator token.
 *
 * @param token Pointer to a `t_token` structure where the
 * 	redirect operator token will be stored.
 * @param end Pointer to a char pointer that points to the
 * 	end of the token in the command line string.
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
 * The lexical analyzer function. It takes a segment of the command
 * 	line and generates a token.
 *
 * @param token Pointer to a `t_token` structure where the generated
 * 	token will be stored.
 * @param begin Pointer to a char pointer that points to the beginning of
 * 	the segment in the command line string.
 * @param end Pointer to a char pointer that points to the end of the segment
 * 	in the command line string.
 *
 * @return SUCCESS_FLAG if the token is generated successfully, ERROR_FLAG
 * 	otherwise.
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
