/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:53:08 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 18:08:13 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO: CHANGE INCLUDES FOR DELIVERY
#include "../include/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_buffer	buffers[MAX_FD];
	t_buffer		*temp;

	temp = &buffers[fd];
	temp->line = NULL;
	if (fd < 0 || fd >= MAX_FD || MAX_FD <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (!*temp->buffer && !read(fd, temp->buffer, BUFFER_SIZE))
			break ;
		temp->line = join_strings(temp->line, temp->buffer);
		if (process_buffer(temp->buffer))
			break ;
	}
	return (temp->line);
}
