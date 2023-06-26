/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ptrrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:24:19 by datran            #+#    #+#             */
/*   Updated: 2023/06/26 18:03:43 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Reallocates memory for a null-terminated array of strings (i.e., an array of 
 * pointers to characters).
 * @param buf A pointer to the current array of strings.
 * @parma before_size The current size of the array, in terms of the number of 
 * elements.
 * @param after_size The desired new size of the array, in terms of the number 
 * of elements.
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
