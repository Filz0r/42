/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/18 16:51:46 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

char *read_map(int fd, t_map *map)
{
    char    *line;
    char    *result;
    size_t  new_size;
    size_t  res_size;

    res_size = 0;
    new_size = 0;
    result = ft_strdup("");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break ;
        new_size = res_size + ft_strlen(line) + 1;
        result = ft_realloc(result, new_size);
        if (map->width == 0)
            map->width = (int)ft_strlen(line) - 1;
        ft_strlcat(result, line, new_size);
        res_size = new_size - 1;
        map->height++;
        free(line);
    }
    return (result);
}