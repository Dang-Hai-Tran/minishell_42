/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:40 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 09:44:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EXEC_H
# define EXEC_H

int	exec_command_line(t_ast **ast);
int	exec_heredoc(t_ast **ast);
int	exec_builtin(char **argv);
int	exec_ast(t_ast *ast);
int	exec_command(t_command *command);
int	exec_subshell(t_pipe_line *pipe_line);
int	exec_simple_command(t_simple_command *simple_command);
int	exec_io_redirect(t_io_redirect *io_redirect);

#endif
