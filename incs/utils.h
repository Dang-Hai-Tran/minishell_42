/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:44 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 22:04:38 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include <stdbool.h>

int		sh_strcmp(char *s1, char *s2);
void	sh_exit_eof(char *command_line);
char	*sh_find_path(char *cmd);
void	*sh_ptrrealloc(void *buf, int before_size, int after_size);
void	*sh_realloc(void *ptr, size_t size);
bool	sh_cmd_is_dir(char *cmd);
char	**sh_get_string_env(void);
void	sh_putline_heredoc(char *line, int fd);
void	free_str_arr(char **env);
void	print_str_arr(char **str);

#endif
