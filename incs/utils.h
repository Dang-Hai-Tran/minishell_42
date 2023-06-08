/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:44 by datran            #+#    #+#             */
/*   Updated: 2023/06/06 14:51:55 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>

int		sh_strcmp(char *s1, char *s2);
void	sh_exit_eof(char *command_line);
void	*sh_calloc(size_t count, size_t size);
char	*sh_find_path(char *cmd);
void	*sh_ptrrealloc(void *buf, int before_size, int after_size);
void	*sh_realloc(void *ptr, size_t size);

#endif
