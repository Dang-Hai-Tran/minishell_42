/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 11:29:51 by datran            #+#    #+#             */
/*   Updated: 2023/07/17 10:19:04 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	change_pwd(t_env *pwd)
{
	char	*tmp;

	if (!pwd)
		return (EXIT_FAILURE);
	tmp = pwd->value;
	pwd->value = getcwd(NULL, 0);
	if (!pwd->value)
		return (throw_error_exit("getcwd", strerror(errno), EXIT_FAILURE));
	if (tmp)
		free(tmp);
	return (EXIT_SUCCESS);
}

static int	cd_home(void)
{
	t_env	*ptr;
	char	*home;
	int		exit_code;

	exit_code = change_pwd(get_env("OLDPWD"));
	ptr = get_env("HOME");
	if (!ptr)
		return (throw_error("cd", NULL, strerror(errno)));
	home = ptr->value;
	exit_code = chdir(home);
	if (exit_code < 0)
		return (throw_error("cd", NULL, strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (EXIT_SUCCESS);
}

/*
	Invalid option -> exit_code = EXIT_FAILURE;
	No such file or directory -> exit_code = EXIT_FAILURE;
*/
int	change_directory(char **argv)
{
	int		exit_code;
	t_env	*old_pwd;

	if (!*(argv + 1) || !**(argv + 1) || !ft_strncmp(*(argv + 1), "--", 3))
		return (cd_home());
	if (*(argv + 2))
		return (throw_error("cd", NULL, "too many arguments"));
	if (!ft_strncmp(*(argv + 1), "-", 2))
	{
		old_pwd = get_env("OLDPWD");
		if (!old_pwd)
			return (throw_error("cd", NULL, "OLDPWD not set"));
		exit_code = chdir(old_pwd->value);
		exit_code = change_pwd(get_env("PWD"));
		ft_putendl_fd(old_pwd->value, STDOUT_FILENO);
		return (exit_code);
	}
	exit_code = change_pwd(get_env("OLDPWD"));
	if (check_option(*(argv + 1)) == true)
		return (throw_error_usage("cd", *(argv + 1)));
	exit_code = chdir(*(argv + 1));
	if (exit_code < 0)
		return (throw_error("cd", *(argv + 1), strerror(errno)));
	exit_code = change_pwd(get_env("PWD"));
	return (exit_code);
}
