/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: colin <colin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 14:55:03 by datran            #+#    #+#             */
/*   Updated: 2023/07/04 23:29:58 by colin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * Extracts the name of an environment variable from a token. It copies the alphanumeric characters
 * from the token until it finds a character that is not alphanumeric or an underscore.
 *
 * @param token The token from which to extract the name.
 *
 * @return The name of the environment variable.
 */
char	*extract_env_name(char *token)
{
	char	*name;
	int		nc;

	nc = 0;
	name = ft_strdup("");
	while (ft_isalnum(*token) || (*token) == '_')
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
 * Replaces a special character environment variable in a token with its value. If the environment variable
 * is $? or $$, it replaces it with the exit code or the process ID, respectively.
 *
 * @param token The token in which to replace the environment variable.
 * @param env_ptr Pointer to the position of the environment variable in the token.
 *
 * @return The token with the environment variable replaced.
 */
char	*replace_env_sc(char *token, char *env_ptr)
{
	char	*sc;
	char	*prev;
	char	*next;
	char	*word;

	if (*(env_ptr + 1) == '?')
		sc = ft_itoa(g_manager.exit_code);
	else if (*(env_ptr + 1) == '$')
		sc = ft_itoa((int)getpid());
	else
		return (ft_strdup(token));
	prev = ft_substr(token, 0, env_ptr - token);
	word = ft_strjoin(prev, sc);
	free(sc);
	free(prev);
	prev = word;
	next = replace_env(env_ptr + 2);
	word = ft_strjoin(word, next);
	free(prev);
	free(next);
	return (word);
}

/**
 * Replaces a named environment variable in a token with its value. It extracts the name of the environment variable,
 * fetches its value from the environment, and replaces the environment variable in the token with its value.
 *
 * @param token The token in which to replace the environment variable.
 * @param env_ptr Pointer to the position of the environment variable in the token.
 *
 * @return The token with the environment variable replaced.
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
 * Replaces all environment variables in a token with their values. It replaces both special character
 * environment variables and named environment variables.
 *
 * @param token The token in which to replace the environment variables.
 *
 * @return The token with the environment variables replaced.
 */
char	*replace_env(char *token)
{
	char	*word;
	char	*env_ptr;

	env_ptr = ft_strchr(token, '$');
	while (env_ptr && *(env_ptr + 1) && !(*(env_ptr + 1) == '?'
			|| ft_isalpha(*(env_ptr + 1)) || *(env_ptr + 1) == '$'))
		env_ptr = ft_strchr(env_ptr + 1, '$');
	if (!env_ptr)
		return (ft_strdup(token));
	if (*(env_ptr + 1) == '?' || *(env_ptr + 1) == '$')
		word = replace_env_sc(token, env_ptr);
	else if (ft_isalpha(*(env_ptr + 1)))
		word = replace_env_name(token, env_ptr);
	else
		word = ft_strdup(token);
	return (word);
}

/**
 * Parses a word. It replaces all environment variables in the word and duplicates it.
 *
 * @param word The word to parse.
 *
 * @return The parsed word.
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
