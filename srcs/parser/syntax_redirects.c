/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:37:21 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:13:36 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initializes a new syntax redirects node. It allocates memory for the AST
 * redirects node and sets the node type to AST_REDIRECTS.
 * It also allocates memory for the redirects data.
 *
 * @param ast_redirects Pointer to the AST redirects node to be initialized.
 */
static void	init_syntax_redirects(t_ast **ast_redirects)
{
	*ast_redirects = ft_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = ft_calloc(1, sizeof(t_redirects));
}

/**
 * Parses redirects. It initializes a redirects node and parses an IO redirect.
 * If the next token type is T_REDIRECT, it parses redirects.
 * If any of these steps fail, it returns an error flag.
 *
 * @param ast_redirects Pointer to the AST redirects node.
 *
 * @return SUCCESS_FLAG if the parsing is successful, ERROR_FLAG otherwise.
 */
int	syntax_redirects(t_ast **ast_redirects)
{
	t_redirects	*redirects;
	t_token		token;

	init_syntax_redirects(ast_redirects);
	redirects = (*ast_redirects)->data;
	if (syntax_io_redirect(&redirects->io_redirect))
		return (ERROR_FLAG);
	token = fetch_token(GET);
	if (token.type == T_REDIRECT)
		if (syntax_redirects(&redirects->redirects))
			return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
