/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:53:08 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 16:31:00 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!*buffer && !read(fd, buffer, BUFFER_SIZE))
			break ;
		line = join_strings(line, buffer);
		if (process_buffer(buffer))
			break ;
	}
	return (line);
}
