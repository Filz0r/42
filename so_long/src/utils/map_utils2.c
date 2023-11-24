/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 11:54:14 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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

// This function checks the pathing after the map_validator is flooded
// returns true if any E or C elements exist
int	check_pathing(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
