/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 12:08:53 by datran            #+#    #+#             */
/*   Updated: 2023/05/02 16:09:51 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] != c && str[i])
				i++;
			if (!str[i])
				return (count);
		}
		i++;
	}
	return (count);
}

static char	*ft_firstword(char *str, char c, size_t *j)
{
	size_t	i;
	size_t	len;
	char	*word;

	i = 0;
	while (str[i] && str[i] == c)
		i++;
	*j = i;
	while (str[*j] && str[*j] != c)
		*j += 1;
	len = *j - i;
	word = ft_substr(str, i, len);
	return (word);
}

char	**ft_split(char const *str, char c)
{
	char	**tab;
	size_t	pos;
	size_t	count;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	count = ft_wordcount((char *)str, c);
	tab = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = NULL;
	while (i < count)
	{
		tab[i] = ft_firstword(((char *)str), c, &pos);
		str += pos;
		i++;
	}
	return (tab);
}
