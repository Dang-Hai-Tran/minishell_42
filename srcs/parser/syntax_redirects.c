/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:37:21 by datran            #+#    #+#             */
/*   Updated: 2023/06/09 15:21:23 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_syntax_redirects(t_ast **ast_redirects)
{
	*ast_redirects = ft_calloc(1, sizeof(t_ast));
	(*ast_redirects)->type = AST_REDIRECTS;
	(*ast_redirects)->data = ft_calloc(1, sizeof(t_redirects));
}

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
