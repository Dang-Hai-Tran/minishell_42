/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:00:57 by datran            #+#    #+#             */
/*   Updated: 2023/07/16 22:03:56 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_str_arr(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s || ", str[i]);
		i++;
	}
	printf("%s", "\n");
}
