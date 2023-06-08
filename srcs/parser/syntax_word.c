/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: datran <datran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:55:03 by datran            #+#    #+#             */
/*   Updated: 2023/06/05 15:43:13 by datran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/**
 * Extracts the name of an environment variable from a given token.
*/
char	*extract_env_name(char *token)
{
	char	*name;
	int		nc;

	nc = 0;
	name = sh_calloc(1, sizeof(char));
	while (ft_isalnum(*token))
	{
		name = sh_realloc(name, nc + 2);
		name[nc] = *token;
		nc++;
		token++;
	}
	name[nc] = '\0';
	return (name);
}

/**
 * Takes a string representing an exit code environment variable and its 
 * location within the input string, and replaces it with the actual exit code 
 * value.
 * @param token A pointer to a string representing the token to be processed.
 * @param env_ptr A pointer to a character representing the location of the 
 * exit code environment variable within the input string.
 * @return Returns a pointer to a string representing the processed token.
*/
char	*replace_env_sc(char *token, char *env_ptr)
{
	char	*sc;
	char	*prev;
	char	*next;
	char	*word;

	if (*(env_ptr + 1) == '?')
		sc = ft_itoa(g_manager.exit_code);
	else
		return (ft_strdup(token));
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(sc);
	word = ft_strjoin(prev, sc);
	free(sc);
	free(prev);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/**
 * Takes a string representing an environment variable and its location within 
 * the input string, and replaces it with its corresponding value.
 * @param token A pointer to a string representing the token to be processed.
 * @param env_ptr A pointer to a character representing the location of the 
 * environment variable within the input string.
 * @return a pointer to a string representing the processed token.
*/
char	*replace_env_name(char *token, char *env_ptr)
{
	char	*name;
	t_env	*env;
	char	*prev;
	char	*next;
	char	*word;

	name = extract_env_name(env_ptr + 1);
	prev = ft_substr(token, 0, env_ptr - token);
	env_ptr += ft_strlen(name);
	env = get_env(name);
	if (env)
	{
		word = ft_strjoin(prev, env->value);
		free(prev);
	}
	else
		word = prev;
	free(name);
	prev = word;
	next = replace_env(env_ptr + 1);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/**
 * Takes a string as input and replaces any environment variables in the string with their values.
 * @param token A pointer to a string representing the token to be processed.
 * @return A pointer to a string representing the processed token.
*/
char	*replace_env(char *token)
{
	char	*word;
	char	*env_ptr;

	env_ptr = ft_strchr(token, '$');
	while (env_ptr && *(env_ptr + 1) && !(*(env_ptr + 1) == '?'
			|| ft_isalpha(*(env_ptr + 1))))
		env_ptr = ft_strchr(env_ptr + 1, '$');
	if (!env_ptr)
		return (ft_strdup(token));
	if (*(env_ptr + 1) == '?')
		word = replace_env_sc(token, env_ptr);
	else if (ft_isalpha(*(env_ptr + 1)))
		word = replace_env_name(token, env_ptr);
	else
		word = ft_strdup(token);
	return (word);
}

/**
 * Takes a string as input and processes it to remove quotes, replace 
 * environment variables with their values and return the resulting string.
 * @param token A pointer to a string representing the token to be processed.
 * @return A pointer to a string representing the processed token.
*/
char	*syntax_word(char *token)
{
	char	*word;
	char	*tmp;

	if (*token == U_DOUBLE_QUOTES)
	{
		word = ft_substr(token, 1, ft_strlen(token) - 2);
		tmp = word;
		word = replace_env(word);
		free(tmp);
	}
	else if (*token == U_SINGLE_QUOTES)
		word = ft_substr(token, 1, ft_strlen(token) - 2);
	else
		word = replace_env(token);
	free(token);
	return (word);
}
