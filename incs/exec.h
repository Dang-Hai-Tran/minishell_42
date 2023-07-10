/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: copeugne <copeugne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:40 by datran            #+#    #+#             */
/*   Updated: 2023/07/10 12:56:15 by copeugne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

int	exec_command_line(t_ast **ast);
int	exec_heredoc(t_ast **ast);
int	exec_builtin(char **argv);
int	exec_general(char **argv);
int	exec_ast(t_ast *ast);
int	exec_command(t_command *command);
int	exec_pipe_line(t_pipe_line *pipe_line);
int	exec_redirects(t_redirects *redirects);
int	exec_subshell(t_pipe_line *pipe_line);
int	exec_simple_command(t_simple_command *simple_command);
int	exec_single_command(t_command *command);
int	exec_io_redirect(t_io_redirect *io_redirect);

#endif
