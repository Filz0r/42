/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:51 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 22:35:43 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

// Calculates the height of the map
int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y] || map[y] != 0)
		y++;
	return (y);
}

// Calculates the width of the map using the first row
int	get_map_width(char **map)
{
	return ((int)ft_strlen(map[0]));
}

// Finds the to_find in the map and allocates it to memory
// and returns it as t_point *, returns NULL if it isn't
// found or if malloc fails.
t_point	*get_point(char **map, char to_find)
{
	t_point	*res;
	int		x;
	int		y;

	y = -1;
	res = malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == to_find)
			{
				*res = (t_point){x, y, (double)x, (double)y};
				return (res);
			}
		}
	}
	free(res);
	return (NULL);
}

// Finds the collectible in the map and allocates it to memory
// and adds each collectible to a linked list
void	get_collectibles(char **map, t_list **lst)
{
	int		y;
	int		x;
	t_point	*temp;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C')
			{
				temp = malloc(sizeof(t_point));
				*temp = (t_point){x * SIZE, y * SIZE, (double)x, (double)y};
				ft_lstadd_back(lst, ft_lstnew((void *)temp));
			}
		}
	}
}
