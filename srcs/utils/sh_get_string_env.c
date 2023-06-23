/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_get_string_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:16:15 by datran            #+#    #+#             */
/*   Updated: 2023/06/23 12:17:12 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_count(void)
{
	t_env	*ptr;
	int		count;

	ptr = g_manager.env;
	count = 0;
	while (ptr)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}

char	**sh_get_string_env(void)
{
	t_env	*ptr;
	char	**ret;
	char	*tmp;
	int		count;
	int		i;

	ptr = g_manager.env;
	count = get_count();
	ret = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!ret)
		exit(EXIT_FAILURE);
	i = 0;
	while (ptr && ptr->value)
	{
		tmp = ft_strjoin(ptr->name, "=");
		ret[i] = ft_strjoin(tmp, ptr->value);
		free(tmp);
		ptr = ptr->next;
		i++;
	}
	return (ret);
}
