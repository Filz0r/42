/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:23:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 14:45:13 by fparreir         ###   ########.fr       */
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

char *generate_player_path(int nb)
{
	char *temp;
	char *path;

	temp = ft_itoa(nb);
	path = ft_strjoin(PLAYER, temp);
	free(temp);
	temp = ft_strjoin(path, ".xpm");
	free(path);
	return (temp);
}