/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olshklya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 17:58:49 by olshklya          #+#    #+#             */
/*   Updated: 2025/10/21 18:38:23 by olshklya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	word_flag;

	count = 0;
	word_flag = 0;
	while (*str)
	{
		if (*str != c && word_flag == 0)
		{
			word_flag = 1;
			count++;
		}
		else if (*str == c)
			word_flag = 0;
		str++;
	}
	return (count);
}

static char	*word_dup(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static char	**alloc_split(const char *str, char c)
{
	char	**split;

	if (!str)
		return (NULL);
	split = malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!split)
		return (NULL);
	return (split);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	int		j;
	int		index;
	char	**split;

	split = alloc_split(str, c);
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(str))
	{
		if (str[i] != c && index < 0)
			index = i;
		else if ((str[i] == c || i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = word_dup(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
