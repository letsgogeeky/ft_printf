/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:29:40 by ramoussa          #+#    #+#             */
/*   Updated: 2023/03/29 22:01:15 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*get_word(char *s, char stop_at)
{
	int		size;
	char	*word;

	size = 0;
	while (s[size] && s[size] != stop_at)
		size++;
	word = (char *)malloc(size + 1);
	if (!word)
		return (NULL);
	size = 0;
	while (s[size] && s[size] != stop_at)
	{
		word[size] = s[size];
		size++;
	}
	word[size] = 0;
	return (word);
}

static int	word_count(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i])
	{
		if (s[i] != c && (!s[i + 1] || s[i + 1] == c))
			word_count++;
		i++;
	}
	return (word_count);
}

void	abort_and_free(char **words, int word_idx)
{
	while (word_idx + 1)
	{
		free(*(words + word_idx));
		*(words + word_idx) = NULL;
		word_idx--;
	}
	free(words);
	words = NULL;
}

int	generate_result(char **words, char *str, char c, int word_idx)
{
	int	success;

	success = 0;
	while (*str && *str == (char)c)
		str++;
	while (*str)
	{
		words[word_idx] = get_word(str, (unsigned char)c);
		if (!words[word_idx])
		{
			abort_and_free(words, word_idx);
			return (0);
		}
		word_idx++;
		success++;
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
	}
	return (success);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**words;
	int		word_idx;
	char	*str;

	if (s == 0)
		return (0);
	str = (char *)s;
	word_idx = 0;
	count = word_count(s, c);
	words = (char **)malloc(sizeof(char *) * (count + 1));
	if (!words || !s)
		return (NULL);
	if (count > 0)
	{
		word_idx = generate_result(words, str, c, word_idx);
		if (!word_idx)
		{
			return (NULL);
		}
	}
	words[word_idx] = 0;
	return (words);
}
