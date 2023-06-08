/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:55:38 by datran            #+#    #+#             */
/*   Updated: 2023/05/01 19:53:19 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_formats(int c, va_list args)
{
	int	i;

	i = 0;
	if ((char)c == 'c')
		i = ft_char_format(va_arg(args, int));
	else if ((char)c == 's')
		i = ft_string_format(va_arg(args, char *));
	else if ((char)c == 'p')
		i = ft_pointer_format(va_arg(args, void *));
	else if ((char)c == 'i' || c == 'd')
		i = ft_decimal_format(va_arg(args, int));
	else if ((char)c == 'u')
		i = ft_unsigned_decimal_format(va_arg(args, unsigned long));
	else if ((char)c == 'x')
		i = ft_hexadecimal_format(va_arg(args, unsigned long));
	else if ((char)c == 'X')
		i = ft_upper_case_hexadecimal_format(va_arg(args, unsigned long));
	else if ((char)c == '%')
		i = ft_percent_format(c);
	return (i);
}
