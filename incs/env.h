/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 11:12:31 by datran            #+#    #+#             */
/*   Updated: 2023/06/08 09:42:34 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# define TMPENV "TMPDIR"
# define TMPKEY "msh-"
# define TMPDIR "/tmp/"
# define PATHENV "PATH"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env				*get_env(char *identifier);
char				*get_env_name(char *argv);
char				*get_env_value(char *argv);
void				add_env(char *name, char *value);

#endif
