/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_simple_command.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:58:21 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Initializes a simple command. If the simple command is not yet initialized, it allocates memory
 * for it and sets its exec_path field. It also allocates memory for argv. If the simple command is already
 * initialized, it increments the argument counter.
 *
 * @param simple_command Pointer to the simple command to be initialized.
 * @param ac Pointer to the argument counter.
 *
 * @return A pointer to argv.
 */
static char	**init_simple_command(t_simple_command **simple_command, int *ac)
{
	char	**argv;

	if (*simple_command == NULL)
	{
		*simple_command = ft_calloc(1, sizeof(t_simple_command));
		(*simple_command)->exec_path = get_combined_word();
		argv = ft_calloc((*ac) + 2, sizeof(char *));
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

/**
 * Parses a simple command. It initializes a simple command and keeps fetching tokens of type T_WORD,
 * adding them to argv, until it finds a token of a different type. If any of these steps fail,
 * it returns an error flag.
 *
 * @param simple_command Pointer to the simple command to be parsed.
 *
 * @return SUCCESS_FLAG if the parsing is successful, ERROR_FLAG otherwise.
 */
int	syntax_simple_command(t_simple_command **simple_command)
{
	int		ac;
	char	**argv;

	ac = 0;
	argv = init_simple_command(simple_command, &ac);
	while (fetch_token(GET).type == T_WORD)
	{
		argv = sh_ptrrealloc(argv, ac, ac + 2);
		argv[ac] = get_combined_word();
		ac++;
	}
	argv[ac] = NULL;
	(*simple_command)->argv = argv;
	return (SUCCESS_FLAG);
}
