/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:29:08 by datran            #+#    #+#             */
/*   Updated: 2023/06/21 12:36:28 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#ifndef BUILTIN_H
# define BUILTIN_H

int				is_builtin(char *exec_path);
int				check_option(char *argv);
int				ft_echo(char **argv);
int				ft_cd(char **argv);
int				ft_pwd(char **argv);
int				ft_env(char **argv);
int				ft_exit(char **argv);
int				ft_export(char **argv);
int				ft_unset(char **argv);
int				check_exit_arg(char *arg);

#endif
