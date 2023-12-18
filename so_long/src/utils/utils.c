/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:23:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 21:38:36 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief Recursive implementation of the flood fill algorithm, to limit call
 * stacks everytime the algorithm finds a '1' or a value that was already filled
 * it starts returning
 * @param map the map we want to fill
 * @param x an x position
 * @param y an y position
 * @param fill_val the value we want to try and change at the position given
 */
void	flood_fill(char **map, int x, int y, char fill_val)
{
	int	width;

	width = get_width(map);
	if (width == -1 || x < 0 || x >= width || y < 0 || y >= get_height(map))
		return ;
	if (map[y][x] == '1' || map[y][x] == fill_val)
		return ;
	map[y][x] = fill_val;
	flood_fill(map, x, (y - 1), fill_val);
	flood_fill(map, x, (y + 1), fill_val);
	flood_fill(map, (x - 1), y, fill_val);
	flood_fill(map, (x + 1), y, fill_val);
}

/**
 * @brief Checks if the given argument is '0', '1', 'P', 'E' or 'C'
 * @param c the char we want to check
 * @return either 0 if the value isn't any of the mentioned char or 1 if it is.
 */
int	invalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

/**
 * @brief Counts the number of rows inside the map
 * @param map a 2D array
 * @return either 0 if the map isn't valid or the number of columns
 */
int	get_height(char **map)
{
	int	res;

	if (*map == NULL)
		return (0);
	res = 0;
	while (map[res])
		res++;
	return (res);
}

/**
 * @brief calculates the width of the entire map and makes sure that the width
 * is always the same for the entire map.
 * @param 2D char ** map
 * @return returns 0 if the map isn't valid, -1 if the width isn't the same
 * across the entire map or the width of the map.
 */
int	get_width(char **map)
{
	int	y;
	int	x;
	int	res;
	int	old_res;

	if (*map == NULL)
		return (0);
	res = 0;
	old_res = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			res++;
		if (y > 0 && res != old_res)
			return (-1);
		old_res = res;
		res = 0;
	}
	return (old_res);
}

/**
 * @brief duplicates a char ** array
 * @param map the array we want to fill
 * @return either NULL if memory allocation fails or a clone of the given
 * argument.
 */
char	**mapdup(char **map)
{
	int		h;
	int		i;
	char	**res;

	i = 0;
	h = get_height(map);
	res = malloc(sizeof(char *) * (h + 1));
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
