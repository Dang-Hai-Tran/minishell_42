/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:17:38 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 00:32:35 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "token.h"

typedef struct s_command		t_command;
typedef struct s_simple_command	t_simple_command;
typedef struct s_redirects		t_redirects;
typedef struct s_io_redirect	t_io_redirect;

/**
 * ast tree generate node
 * pipe_line	-> 0
 * command		-> 1
 * redirects	-> 2
*/
typedef enum e_ast_type
{
	AST_NULL,
	AST_PIPELINE,
	AST_COMMAND,
	AST_REDIRECTS
}	t_ast_type;

typedef struct s_ast
{
	t_ast_type					type;
	void						*data;
}	t_ast;

/* <pipe_line>   -> <command> { '|' <pipe_line> } */
typedef struct s_pipe_line
{
	t_ast						*command;
}	t_pipe_line;

/* <command> -> [ <simple_command> ][ <redirects> ][pipe_line] */
typedef struct s_command
{
	struct s_simple_command		*simple_command;
	t_ast						*redirects;
	t_ast						*pipe_line;
}	t_command;

/* <simple_command> -> <exec_path> { <argv> } */
typedef struct s_simple_command
{
	char						*exec_path;
	char						**argv;
}	t_simple_command;

/* <redirects> -> <io_redirect> { <redirects> } */
typedef struct s_redirects
{
	struct s_io_redirect		*io_redirect;
	t_ast						*redirects;
}	t_redirects;

/* <io_redirect> -> <redirect_op> <file_path> */
typedef struct s_io_redirect
{
	t_redirect_op				redirect_op;
	char						*file_path;
	char						*end_text;
}	t_io_redirect;

#endif
