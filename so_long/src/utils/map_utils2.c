/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:22:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/19 20:59:50 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief Finds the position of 'P' in the given map and sets the given x and y
 * pointers to its values
 * @param map the map array
 * @param pos_x a pointer to an int
 * @param pos_y a pointer to an int
 */
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
}

/**
 * @brief checks if any 'E' or 'C' elements exist in the map after its flooded
 * @param the 2d map array
 * @return 1 if any 'E' or 'C' exist 0 if not
 */
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

/**
 * @brief this function is responsible for trimming the 2D array
 * given by read_map.
 * @param map char ** map that we want to remove te '\\n' symbol from the map
 * @param size the size of the array
 * @return either returns NULL when the map array contains empty lines or
 * returns the trimmed map pointer.
 */
char	**trim_map(char **map, int size)
{
	char	*temp;
	int		i;

	i = 0;
	while (map[i] && i < size)
	{
		temp = ft_strclean(map[i], '\n', ft_strlen(map[i]));
		if (ft_strlen(temp) == 0)
			return (free(temp), ft_fsplit(map), NULL);
		free(map[i]);
		map[i] = temp;
		i++;
	}
	return (map);
}
