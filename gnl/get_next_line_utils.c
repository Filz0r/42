/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:04:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/16 15:24:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*buffer;
	size_t	i;

	i = 0;
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	buffer = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (s1[i] != '\0')
	{
		buffer[i] = s1[i];
		i++;
	}
	while (*s2 != '\0')
		buffer[i++] = *s2++;
	buffer[i] = 0;
	free(s1);
	return (buffer);
}

char	*ft_strchr(char *str, char c)
{
	if (!str)
		return (NULL);
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (0);
}
