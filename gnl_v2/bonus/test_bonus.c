/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:18:18 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 17:55:27 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd[5];
	char	*line;

	fd[0] = open("./test_files/file1.txt", O_RDONLY);
	fd[1] = open("./test_files/file2.txt", O_RDONLY);
	fd[2] = open("./test_files/file3.txt", O_RDONLY);
	fd[3] = open("./test_files/file4.txt", O_RDONLY);
	fd[4] = open("./test_files/file5.txt", O_RDONLY);
	for (int i = 0; i < 5; i++) {
		if (fd[i] == -1) {
			for (int k = 0; k <= i; k++)
				close(fd[i]);
			perror("Error opening the file");
			return (1);
		}

	}
	for (int i = 0; i < 5; i++) {
		while ((line = get_next_line(fd[i])) != NULL) {
			printf("fd[%d]: |%s|", i, line);
			free(line);
		}
	}
	free(line);
	for (int i = 0; i < 5; i++)
		if (fd[i] > 0)
			close(fd[i]);
	return (0);
}