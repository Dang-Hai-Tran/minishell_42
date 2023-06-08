/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:56:42 by datran            #+#    #+#             */
/*   Updated: 2023/05/01 19:51:52 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			i;

	i = 0;
	va_start(args, fmt);
	i += ft_input_parser(fmt, args);
	va_end(args);
	return (i);
}
