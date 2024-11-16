/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:53:08 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 15:53:22 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffers[MAX_FD];
	char		*line;
	char		temp_buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (clear_buffers(buffers));
	line = NULL;
	while (1)
	{
		if (!buffers[fd])
			buffers[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!*buffers[fd])
		{
			bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				break ;
			temp_buffer[bytes_read] = '\0';
			buffers[fd] = join_strings(buffers[fd], temp_buffer);
		}
		line = join_strings(line, buffers[fd]);
		if (process_buffer(buffers[fd]))
			break ;
	}
	return (line);
}
