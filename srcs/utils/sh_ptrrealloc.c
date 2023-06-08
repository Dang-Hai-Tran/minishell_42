/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ptrrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:24:19 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 11:24:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*sh_ptrrealloc(void *buf, int before_size, int after_size)
{
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)malloc(sizeof(char *) * after_size);
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}
