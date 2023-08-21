/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:35:21 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/24 13:22:20 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_get_word_length(const char *s, char c, int i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static int	ft_count_words(char const *str, char c)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			counter++;
		while (*str && *str != c)
			str++;
	}	
	return (counter);
}

static char	*ft_get_word(const char *str, char c, int *pos)
{
	int		k;
	int		i;
	int		word_length;
	char	*buffer;

	k = 0;
	i = 0;
	if (*pos > 0)
		i = *pos;
	word_length = ft_get_word_length(str, c, i) - i;
	if (word_length > 0)
	{
		buffer = (char *)malloc((word_length + 1) * sizeof(char));
		if (!buffer)
			return (0);
		while (i < *pos + word_length)
			buffer[k++] = str[i++];
		buffer[k] = 0;
		*pos = i;
	}
	else
		return (ft_get_word(str, c, ((*pos)++, pos)));
	return (buffer);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	int		words;
	char	*word;
	char	**buffer;

	i = 0;
	k = 0;
	words = ft_count_words(s, c);
	buffer = (char **)malloc((words + 1) * sizeof(char *));
	if (!buffer)
		return (0);
	while (i < words)
	{
		if (k <= (int)ft_strlen(s))
		{
			word = ft_get_word(s, c, &k);
			buffer[i] = word;
		}
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
