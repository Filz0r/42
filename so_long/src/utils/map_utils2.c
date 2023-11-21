/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 16:23:31 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char	*read_map(int fd)
{
	char		*line;
	char		*result;
	size_t		new_size;
	size_t		res_size;

	res_size = 0;
	result = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_size = res_size + ft_strlen(line) + 1;
		result = ft_realloc(result, new_size);
		ft_strlcat(result, line, new_size);
		res_size = new_size - 1;
		free(line);
	}
	return (result);
}

int	get_map_height(char **map)
{
	int	res;

	if (*map == NULL)
		return (0);
	res = 0;
	while (map[res])
		res++;
	return (res);
}

int	get_map_width(char **map)
{
	int	res;

	if (*map == NULL)
		return (0);
	res = 0;
	while (map[0][res])
		res++;
	return (res);
}
