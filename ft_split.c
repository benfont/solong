/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitlopez <aitlopez@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:00:56 by aitlopez          #+#    #+#             */
/*   Updated: 2023/02/24 21:12:13 by aitlopez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	word_counter(char const *s, char c)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			i++;
		else
		{
			j++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
	}
	return (j);
}

static void	memfree(char **str, size_t j)
{
	size_t	k;

	k = 0;
	while (k < j)
	{
		free(str[k]);
		k++;
	}
	free(str);
}

static char	**malloc_strings(char const *s, char c, char **words, size_t i)
{
	int		j;
	size_t	start;

	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] != c && i < ft_strlen(s))
				i++;
			words [j] = ft_substr(s, start, (i - start));
			if (!words[j])
			{
				memfree(words, j);
				return (NULL);
			}
			j++;
		}
	}
	words[j] = 0;
	return (words);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	char		**words;

	words = (char **)malloc(sizeof(char *) * (word_counter(s, c) + 1));
	if (!words)
		return (NULL);
	i = 0;
	return (malloc_strings(s, c, words, i));
}
