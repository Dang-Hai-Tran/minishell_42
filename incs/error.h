/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:36 by datran            #+#    #+#             */
/*   Updated: 2023/07/22 21:35:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERROR_FLAG 1
# define SUCCESS_FLAG 0
# define EXIT_EACCES 126
# define EXIT_ENOENT 127
# define EXIT_SYNTAXERR 2

int	throw_error(char *cmd, char *argv, char *err);
int	throw_error_env(char *cmd, char *argv);
int	throw_error_exit(char *cmd, char *err, int exit_code);
int	throw_error_usage(char *cmd, char *argv);
int	throw_error_syntax(t_token token);

#endif
