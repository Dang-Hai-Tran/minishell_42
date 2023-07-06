/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:35:09 by datran            #+#    #+#             */
/*   Updated: 2023/07/06 12:06:00 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Compares two strings.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return Returns an integer greater than, equal to, or less than 0, according as the string s1 is greater than, 
 * equal to, or less than the string s2.
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
