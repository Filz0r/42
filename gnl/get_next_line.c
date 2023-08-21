/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/16 15:20:37 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlen(buffer))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = buffer[i];
	return (line);
}

char	*ft_del_line(char *buffer)
{
	int		i;
	int		k;
	char	*result;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	result = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (buffer[i])
		result[k++] = buffer[i++];
	result[k] = '\0';
	free(buffer);
	return (result);
}

char	*ft_get_buffer(char *buffer, int fd)
{
	char		*temp;
	int			b;

	temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	b = 1;
	while (!(ft_strchr(buffer, '\n')) && b != 0)
	{
		b = read(fd, temp, BUFFER_SIZE);
		if (b == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[b] = '\0';
		buffer = ft_strjoin(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_del_line(buffer);
	return (line);
}
