/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:56:33 by datran            #+#    #+#             */
/*   Updated: 2023/05/01 19:53:59 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_prefix(char *str)
{
	int	i;

	i = ft_string_format(str);
	return (i);
}

int	ft_pointer_format(void *ptr_address)
{
	int				i;
	char			*str;
	unsigned long	address;

	if (!ptr_address)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	address = (unsigned long)ptr_address;
	i = ft_print_prefix("0x");
	str = ft_itoa_base(address, "0123456789abcdef");
	i = i + ft_string_format(str);
	free(str);
	return (i);
}
