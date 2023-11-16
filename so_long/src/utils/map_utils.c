/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:36:27 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/16 21:19:11 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// Goes trough the first and last rows and checks if they are '1'.
// Also goes trough all the rows and checks if the first and last char are '1'.
int	is_walled(t_map *m)
{
	int	x;
	int	y;

	if (m == NULL)
		return (1);
	x = -1;
	while (m->map[0][++x])
		if (m->map[0][x] != '1')
			return (1);
	x = -1;
	while (m->map[m->height - 1][++x])
		if (m->map[m->height - 1][x] != '1')
			return (1);
	y = -1;
	while (m->map[++y])
		if (m->map[y][0] != '1' || m->map[y][m->width - 1] != '1')
			return (1);
	return (0);
}

// checks if height equals width
int	is_rectangle(t_map *m)
{
	return (m == NULL || m->height == m->width);
}

// validates that there is only 1 player and exit and at least 1 collectible.
int	validate_details(t_map *m)
{
	return (m == NULL
		|| m->players > 1 || m->exits > 1
		|| m->collectibles == 0);
}

// Goes trough the entire map char by char looking for invalid chars.
int	check_for_invalid(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (!invalid_char(m->map[y][x]))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// Finds the player in the map and sets his position on the map pointer.
void	find_player(t_map *m)
{
	int	x;
	int	y;

	if (m == NULL)
		return ;
	y = 0;
	while (m->map[y])
	{
		x = 0;
		while (m->map[y][x])
		{
			if (m->map[y][x] == 'P')
			{
				m->player->x = x;
				m->player->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
	m->player = NULL;
}




