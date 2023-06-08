/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:27:09 by datran            #+#    #+#             */
/*   Updated: 2023/05/01 19:53:10 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_negative(int *value)
{
	int	i;

	i = 0;
	if (*value == INT_MIN)
	{
		ft_putstr_fd("-2", 1);
		i += 2;
		*value = 147483648;
	}
	else if (*value < 0)
	{
		ft_putchar_fd('-', 1);
		i++;
		*value *= -1;
	}
	return (i);
}

int	ft_decimal_format(int value)
{
	int		i;
	char	*str;

	i = ft_is_negative(&value);
	str = ft_itoa_base(value, "0123456789");
	i = i + ft_string_format(str);
	free(str);
	return (i);
}
