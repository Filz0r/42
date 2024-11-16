/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:54:06 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 17:51:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#  define BUFFER_SIZE 1
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

typedef struct s_buffer	t_buffer;

struct	s_buffer
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line;
};

char	*get_next_line(int fd);
char	*join_strings(char *s1, char *s2);
int		slen(const char *string);
int		process_buffer(char *buffer);


#endif //GET_NEXT_LINE_BONUS_H
