/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:04:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 15:01:43 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

/**
 * @brief a queue based implementation of flood_fill that is used to determine
 * the positions of the tiles that we want to flood with the enemies.
 * @param map a pointer to the t_map struct stored inside t_game.
 * @param pt the point where we want to start to flood fill from.
 * @param q a pointer to the queue that is allocated inside the t_game struct.
 *
 * This function basically does the same thing as the map parser function does.
 * It first clones the map and creates an temporary queue where we are going to
 * store various positions we want to check if we can fill. After that we keep
 * filling our temporary queue with points and we check if it is either a wall
 * or a tile that we have already visited, if we have we go to the next
 * iteration of the loop. The reasoning behind this approach is simple, I was
 * trying to exponentially increase the difficulty of the game as it went on
 * and doing that with recursion caused issues (call stack told me to
 * take a walk) and decided that it would be safer to calculate all this
 * data inside an array before allocating memory for the positions we
 * want to print the flames at, this made the program not only really stable
 * but also made it consume less memory overall.
 */
void	light_map(t_map *map, t_point pt, t_queue *q)
{
	t_point	current;
	t_queue	*points_queue;
	char	**temp_map;

	points_queue = create_queue(count_fillable_tiles(map->map));
	add_to_queue(points_queue, pt);
	temp_map = map_clone(map);
	while (points_queue->front != -1)
	{
		current = remove_from_queue(points_queue);
		if (current.x < 0 || current.y < 0 || current.y >= map->height
			|| current.x >= map->width || temp_map[current.y][current.x] == '1'
			|| temp_map[current.y][current.x] == 'F')
			continue ;
		temp_map[current.y][current.x] = 'F';
		add_to_queue(q, current);
		add_to_queue(points_queue, (t_point){current.x, current.y - 1, 0, 0});
		add_to_queue(points_queue, (t_point){current.x, current.y + 1, 0, 0});
		add_to_queue(points_queue, (t_point){current.x - 1, current.y, 0, 0});
		add_to_queue(points_queue, (t_point){current.x + 1, current.y, 0, 0});
	}
	free_queue(points_queue);
	clean_map(temp_map);
}
