/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:47 by datran            #+#    #+#             */
/*   Updated: 2023/06/07 23:53:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUBSHELL_H
# define SUBSHELL_H
# include <sys/types.h>

pid_t	create_subshell(t_pipe_line *pipe_line);
void	wait_subshell(pid_t last_pid);

#endif
