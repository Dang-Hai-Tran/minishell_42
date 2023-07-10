/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:26:07 by datran            #+#    #+#             */
/*   Updated: 2023/07/10 16:19:24 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initializes a new syntax command. It allocates memory for the AST
 * command node and sets the node type to AST_COMMAND.
 * It also allocates memory for the command data.
 *
 * @param ast_command Pointer to the AST command node to be initialized.
 */
static void	init_syntax_command(t_ast **ast_command)
{
	*ast_command = ft_calloc(1, sizeof(t_ast));
	(*ast_command)->type = AST_COMMAND;
	(*ast_command)->data = ft_calloc(1, sizeof(t_command));
}

/**
 * Parses a command. It keeps fetching tokens until it finds a token that
 * is not of type T_WORD or T_REDIRECT. For each token of type T_WORD,
 * it parses a simple command, and for each token of type T_REDIRECT,
 * it parses redirects. If any of the parsing fails, it returns an error flag.
 *
 * @param ast_command Pointer to the AST command node.
 *
 * @return SUCCESS_FLAG if the parsing is successful, ERROR_FLAG otherwise.
 */
int	syntax_command(t_ast **ast_command)
{
	t_command	*command;
	t_ast		**ast_redirects;
	t_token		token;

	token = fetch_token(GET);
	init_syntax_command(ast_command);
	command = (*ast_command)->data;
	ast_redirects = &command->redirects;
	while (token.type == T_WORD || token.type == T_REDIRECT)
	{
		printf("Token value: %s, token type: %u\n", token.value, token.type);
		if (token.type == T_WORD)
		{
			if (syntax_simple_command(&command->simple_command))
				return (ERROR_FLAG);
		}
		else if (token.type == T_REDIRECT)
		{
			if (syntax_redirects(ast_redirects))
				return (ERROR_FLAG);
		}
		token = fetch_token(GET);
	}
	return (SUCCESS_FLAG);
}
