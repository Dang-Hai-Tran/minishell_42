/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ptrrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:24:19 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 13:30:49 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Reallocates a buffer with a new size. The function copies the existing data
 * into the new buffer and then frees the old buffer.
 *
 * @param buf The old buffer to reallocate.
 * @param before_size The size of the old buffer.
 * @param after_size The size of the new buffer.
 * @return Returns a pointer to the new buffer.
 */
void	*sh_ptrrealloc(void *buf, int before_size, int after_size)
{
	int		idx;
	char	**src;
	char	**dst;

	src = (char **)buf;
	dst = (char **)ft_calloc(after_size, sizeof(char *));
	idx = 0;
	while (idx < before_size)
	{
		dst[idx] = src[idx];
		idx++;
	}
	free(buf);
	return ((void *)dst);
}
