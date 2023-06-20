/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:35:09 by datran            #+#    #+#             */
/*   Updated: 2023/06/20 11:16:22 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Compares the two strings character by character until a difference is found or one of the strings ends. It then returns an integer value indicating the relationship between the strings.
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return If the two strings are equal, it returns 0. If the first string is greater than the second string, it returns a positive integer. If the second string is greater than the first string, it returns a negative integer.
*/
int	sh_strcmp(char *s1, char *s2)
{
	size_t	n;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		n = s1_len;
	else
		n = s2_len;
	return (ft_strncmp(s1, s2, n));
}
