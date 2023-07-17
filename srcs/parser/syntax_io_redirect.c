/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_io_redirect.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 16:45:28 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 10:25:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Parses an IO redirection. It initializes an IO redirect node, 
 * matches the redirection operator, and sets the redirect op field of the
 * node accordingly. If the redirection operator is a heredoc, it gets the
 * combined heredoc word, otherwise, it gets the combined word. 
 * If any of these steps fail, it returns an error flag.
 *
 * @param io_redirect Pointer to the IO redirect node.
 *
 * @return SUCCESS_FLAG if the parsing is successful, ERROR_FLAG otherwise.
 */
int	syntax_io_redirect(t_io_redirect **io_redirect)
{
	char	*redirect_op;

	*io_redirect = ft_calloc(1, sizeof(t_io_redirect));
	redirect_op = match(T_REDIRECT);
	if (!ft_strncmp(redirect_op, "<", 2))
		(*io_redirect)->redirect_op = R_IN;
	else if (!ft_strncmp(redirect_op, ">", 2))
		(*io_redirect)->redirect_op = R_OUT;
	else if (!ft_strncmp(redirect_op, ">>", 3))
		(*io_redirect)->redirect_op = R_APPEND;
	else if (!ft_strncmp(redirect_op, "<<", 3))
		(*io_redirect)->redirect_op = R_HEREDOC;
	else
		return (ERROR_FLAG);
	free(redirect_op);
	if ((*io_redirect)->redirect_op == R_HEREDOC)
		(*io_redirect)->end_text = get_combined_heredoc_word();
	else
		(*io_redirect)->file_path = get_combined_word();
	if ((*io_redirect)->redirect_op == R_HEREDOC)
		return (SUCCESS_FLAG);
	if (!(*io_redirect)->file_path)
		return (ERROR_FLAG);
	return (SUCCESS_FLAG);
}
