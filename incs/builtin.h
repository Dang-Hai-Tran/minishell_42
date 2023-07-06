/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:29:08 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef BUILTIN_H
# define BUILTIN_H

int				is_builtin(char *exec_path);
int				check_option(char *argv);
int				echo_command(char **argv);
int				change_directory(char **argv);
int				perform_pwd(char **argv);
int				env_command(char **argv);
int				exit_command(char **argv);
int				perform_export(char **argv);
int				perform_unset(char **argv);
int				validate_exit_arg(char *arg);

#endif
