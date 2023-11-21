/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:36:27 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 16:25:08 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// Goes through the first and last rows and checks if they are '1'.
// Also goes through all the rows and checks if the first and last char are '1'.
int	is_walled(char **map)
{
	int	x;
	int	y;

	if (*map == NULL)
		return (1);
	x = -1;
	while (map[0][++x])
		if (map[0][x] != '1')
			return (1);
	x = -1;
	while (map[get_map_height(map) - 1][++x])
		if (map[get_map_height(map) - 1][x] != '1')
			return (1);
	y = -1;
	while (map[++y])
		if (map[y][0] != '1' || map[y][get_map_width(map) - 1] != '1')
			return (1);
	return (0);
}

// checks if height equals width
int	is_rectangle(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = -1;
	height = 0;
	if (*map == NULL)
		return (0);
	while (map[++y])
	{
		x = -1;
		width = 0;
		while (map[y][++x])
			if (map[y][x] && map[y][x] != '\n')
				width++;
		height++;
	}
	return (width == height);
}

// validates that there is only 1 player and exit and at least 1 collectible.
int	validate_details(char **map)
{
	int	collectibles;
	int	players;
	int	exits;
	int	x;
	int	y;

	collectibles = 0;
	players = 0;
	exits = 0;
	y = -1;
	if (*map == NULL)
		return (0);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			handle_chars(map[y][x], &collectibles, &exits, &players);
	}
	return ((players > 1 || exits > 1) || collectibles < 1);
}

void	handle_chars(char c, int *collectible, int *exits, int *players)
{
	if (c == 'E')
		(*exits)++;
	else if (c == 'P')
		(*players)++;
	else if (c == 'C')
		(*collectible)++;
}

// Goes through the entire map char by char looking for invalid chars.
int	check_for_invalid(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!invalid_char(map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// Finds the player in the map and sets his position on the map pointer.
void	find_player(char **map, int *pos_x, int *pos_y)
{
	int	x;
	int	y;

	if (*map == NULL)
		return ;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				*pos_x = x;
				*pos_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	*map = NULL;
}
