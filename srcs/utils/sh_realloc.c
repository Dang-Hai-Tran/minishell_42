/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:39:31 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 11:14:09 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Dynamically allocates a block of memory of the specified size. It then copies the contents of the old memory block pointed to by ptr to the new memory block. Finally, it frees the old memory block and returns a pointer to the new memory block.
 * @param ptr A pointer to the memory block previously allocated with malloc, calloc or realloc.
 * @param size The new size for the memory block.
 * @return If the function succeeds in allocating the required memory, it returns a pointer to the newly allocated memory block. If the function fails to allocate the required memory, it returns NULL.
*/
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
