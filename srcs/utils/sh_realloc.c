/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:31 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Reallocates a buffer with a new size. The function copies the existing data into the new buffer and 
 * then frees the old buffer.
 *
 * @param ptr The old buffer to reallocate.
 * @param size The size of the new buffer.
 * @return Returns a pointer to the new buffer.
 */
void	*sh_realloc(void *ptr, size_t size)
{
	int		i;
	char	*src;
	char	*dst;

	i = 0;
	src = (char *)ptr;
	dst = (char *)ft_calloc(size, sizeof(char));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	free(ptr);
	return ((void *)dst);
}
