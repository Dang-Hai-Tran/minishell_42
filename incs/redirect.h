/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:55 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 09:47:43 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECT_H
# define REDIRECT_H

# define READ 0
# define WRITE 1
# define ERROR 2
# define TRASH_PATH "/dev/null"
# define BACKUP_FD 255

int	redirect_in_file(char *file_path);
int	redirect_out_file(char *file_path);
int	redirect_append_file(char *file_path);
int	redirect_heredoc(char *end_text, char *heredoc_path);
int	backup_std_fd(int std_fd[3]);
int	reset_std_fd(int std_fd[3]);

#endif
