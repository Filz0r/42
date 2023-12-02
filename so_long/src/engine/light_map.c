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
