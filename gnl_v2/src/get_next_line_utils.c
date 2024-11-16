/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:53:13 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/16 16:31:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	slen(const char *str)
{
	int	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

char	*join_strings(char *str1, char *str2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = malloc((slen(str1) + slen(str2)) + 1);
	while (str1 && str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		result[i++] = str2[j++];
		if (str2[j] == '\n')
		{
			result[i++] = str2[j];
			break ;
		}
	}
	result[i] = '\0';
	free(str1);
	return (result);
}

int	process_buffer(char *buffer)
{
	int	newline_found;
	int	i;
	int	k;

	newline_found = 0;
	i = 0;
	k = 0;
	while (buffer[i])
	{
		if (newline_found)
			buffer[k++] = buffer[i];
		if (buffer[i] == '\n')
			newline_found = 1;
		buffer[i++] = '\0';
	}
	return (newline_found);
}
