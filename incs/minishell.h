/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:05:34 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 09:47:18 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* CUSTOM HEADER FILE */
# include "ast.h"
# include "env.h"
# include "error.h"
# include "exec.h"
# include "parser.h"
# include "redirect.h"
# include "sh_signal.h"
# include "subshell.h"
# include "utils.h"
# include "builtin.h"
# include "../libft/libft.h"

/* BUILTIN HEADER FILE */
# include <stdio.h>
# include <string.h>
# include <sys/errno.h>
# include <stdbool.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <readline/history.h>
# include <readline/readline.h>

# define PS1 "msh $ "

/* STRUCTURE */
typedef struct s_env	t_env;
typedef struct s_manager
{
	t_env				*env;
	char				*command_line;
	int					rc;
	int					quote_error;
	int					exit_code;
}	t_manager;

extern t_manager		g_manager;

#endif
