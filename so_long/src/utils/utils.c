/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:23:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 11:48:34 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// This function fills the map array that we store in our map pointer
void	flood_fill(char **map, int x, int y, char fill_val)
{
	if (x < 0 || x >= get_map_width(map) || y < 0 || y >= get_map_height(map))
		return ;
	if (map[y][x] == '1' || map[y][x] == fill_val)
		return ;
	map[y][x] = fill_val;
	flood_fill(map, x, (y - 1), fill_val);
	flood_fill(map, x, (y + 1), fill_val);
	flood_fill(map, (x - 1), y, fill_val);
	flood_fill(map, (x + 1), y, fill_val);
}

// Checks if the passed char is valid for the map.
int	invalid_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C');
}

// Counts how many rows exist inside the file
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

// counts how many columns exist inside the first row of the map
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

// Creates a new map from an existing map variable
char	**mapdup(char **map)
{
	int		h;
	int		i;
	char	**res;

	i = 0;
	h = get_map_height(map);
	res = malloc(sizeof(char *) * (h + 1));
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
