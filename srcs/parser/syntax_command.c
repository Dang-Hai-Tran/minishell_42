/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:26:07 by datran            #+#    #+#             */
/*   Updated: 2023/06/11 21:08:12 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Initializes a new AST node of type AST_COMMAND and sets its associated data 
 * to a t_command struct.
 * @param ast_command A pointer to a pointer to a t_ast struct that will be 
 * initialized as a new command node in the AST.
*/
static void	init_syntax_command(t_ast **ast_command)
{
	*ast_command = ft_calloc(1, sizeof(t_ast));
	(*ast_command)->type = AST_COMMAND;
	(*ast_command)->data = ft_calloc(1, sizeof(t_command));
}

/**
 * Parses a command in the input stream and creates an AST node to represent 
 * it. It calls other functions to parse individual components of the command, 
 * such as simple commands and redirects.
 * @param ast_command A pointer to a pointer to a t_ast struct that will be 
 * updated with information about the current command in the input stream. The 
 * ast_command pointer will be updated to point to the root node of the command 
 * AST.
 * 
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
