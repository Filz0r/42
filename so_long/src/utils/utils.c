/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:23:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/19 02:34:47 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// This function fills the map array that we store in our map pointer
void	flood_fill(t_map *m, int x, int y, char fill_val)
{
	if (!m)
		return ;
	if (x < 0 || x >= m->width || y < 0 || y >= m->height)
		return ;
	if (m->map_validator[y][x] == '1' || m->map_validator[y][x] == fill_val)
		return ;
	m->map_validator[y][x] = fill_val;
	flood_fill(m, x, (y - 1), fill_val);
	flood_fill(m, x, (y + 1), fill_val);
	flood_fill(m, (x - 1), y, fill_val);
	flood_fill(m, (x + 1), y, fill_val);
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