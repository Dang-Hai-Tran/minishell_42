/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:58:21 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 11:25:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**init_simple_command(t_simple_command **simple_command, int *ac)
{
	char	**argv;

	if (*simple_command == NULL)
	{
		*simple_command = sh_calloc(1, sizeof(t_simple_command));
		(*simple_command)->exec_path = get_combined_word();
		argv = sh_calloc((*ac) + 2, sizeof(char *));
		argv[(*ac)++] = (*simple_command)->exec_path;
	}
	else
	{
		argv = (*simple_command)->argv;
		while (argv[(*ac)])
			(*ac)++;
	}
	return (argv);
}
int	syntax_simple_command(t_simple_command **simple_command)
{
	int		ac;
	char	**argv;

	ac = 0;
	argv = init_simple_command(simple_command, &ac);
	while (fetch_token(GET).type == T_WORD)
	{
		argv = sh_ptrrealloc(argv, ac, ac + 2);
		argv[ac++] = get_combined_word();
	}
	argv[ac] = NULL;
	(*simple_command)->argv = argv;
	return (SUCCESS_FLAG);
}
