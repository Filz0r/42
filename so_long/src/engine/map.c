/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:51 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 12:13:30 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief calculates the height of the given char **map
 * @param map that darn valid char ** array
 * @return returns the height of the map.
 */
int	get_map_height(char **map)
{
	int	y;

	y = 0;
	while (map[y] || map[y] != 0)
		y++;
	return (y);
}

/**
 * @brief calculates the width of the first row of the map, this is safe in here
 * because we validated the map before, only then.
 * @param map that darn valid char ** array.
 * @return returns the width of the first row of the map.
 */
int	get_map_width(char **map)
{
	return ((int)ft_strlen(map[0]));
}

/**
 * @brief finds all the 'C' chars inside the map and adds them to a linked
 * list and increments the counter.
 * @param map the map we are reading
 * @param lst a reference to the linked list where we store everything.
 */
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

/**
 * @brief basically a free of the result of an ft_split.
 * @param map the array we want to free.
 */
void	clean_map(char **map)
{
	int		i;

	i = 0;
	while (map[i] != 0)
		free(map[i++]);
	free(map);
}
