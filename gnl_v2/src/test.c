/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:18:18 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/15 14:33:07 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening the file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL) {
		printf("|%s|", line);
		free(line);
	}
	close(fd);
	return (0);
}