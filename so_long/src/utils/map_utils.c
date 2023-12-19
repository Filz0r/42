/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:36:27 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/17 21:19:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief goes trough the entire map and checks if its surrounded by '1'
 * @param map the map we want to check
 * @return 1 if the map is surrounded 0 if it isn't.
 */
int	is_walled(char **map)
{
	int	x;
	int	y;
	int	width;

	if (*map == NULL)
		return (1);
	width = get_width(map);
	if (width == -1)
		return (1);
	x = -1;
	while (map[0][++x])
		if (map[0][x] != '1')
			return (1);
	x = -1;
	while (map[get_height(map) - 1][++x])
		if (map[get_height(map) - 1][x] != '1')
			return (1);
	y = -1;
	while (map[++y] != 0)
		if (map[y][0] != '1'
			|| (map[y][width - 1] != '\0' && map[y][width - 1] != '1'))
			return (1);
	return (0);
}

/**
 * @brief checks if the maps width or height are equal (yes you can determine if
 * something is square or not like this)
 * @param map the 2D char array we want to validate
 * @return 1 if width and height are equal 0 if not
 */
int	is_rectangle(char **map)
{
	int	x;
	int	y;
	int	width;
	int	height;

	y = -1;
	height = 0;
	if (!map || *map == NULL)
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

//
/**
 * @brief validates that there is only 1 player and exit and
 * at least 1 collectible.
 * @param map char ** array we want to validate
 * @return 1 if conditions are met 0 if not.
 *
 * This function makes use of an secondary function that gets the pointers to
 * the counters we declare in this function, because well fuck the Norm.
 */
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
	return ((players != 1 || exits != 1) || collectibles < 1);
}

/**
 * @brief this functions checks if the passed char is 'E', 'P' or 'C' and
 * if it is it increments the values of the respective passed pointers.
 * @param c char we want to check
 * @param collectible pointer to collectible counter
 * @param exits pointer to exit counter
 * @param players pointer to player counter
 *
 */
void	handle_chars(char c, int *collectible, int *exits, int *players)
{
	if (c == 'E')
		(*exits)++;
	else if (c == 'P')
		(*players)++;
	else if (c == 'C')
		(*collectible)++;
}

/**
 * @brief goes trough the passed map and checks if any of the present chars
 * are not the ones required for the map to be valid.
 * @param map 2D char array we want to validate
 * @return either 1 if a char inside the map is invalid or 0 if there is none.
 */
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
