/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:31 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 15:43:39 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*sh_realloc(void *ptr, size_t size)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *)ptr;
	dst = (char *)malloc(size);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return ((void *)dst);
}
