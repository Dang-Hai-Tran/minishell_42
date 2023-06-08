/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:05:25 by datran            #+#    #+#             */
/*   Updated: 2022/11/22 13:24:20 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_len;
	size_t	slen;

	slen = ft_strlen(s);
	if (slen <= (size_t)start)
		return (ft_strdup(""));
	if (slen - start < len)
		sub_len = slen - start;
	else
		sub_len = len;
	sub = (char *)malloc(sub_len + 1);
	if (!s || !sub)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_len + 1);
	return (sub);
}
