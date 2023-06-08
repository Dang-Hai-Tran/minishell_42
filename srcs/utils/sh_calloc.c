/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 16:35:55 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 00:12:21 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "minishell.h"

void	*sh_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*res;

	res = (void *)malloc(size * count);
	if (!(res))
		exit(EXIT_FAILURE);
	i = 0;
	while (i < size * count)
	{
		*((char *)res + i) = '\0';
		i++;
	}
	return (res);
}
