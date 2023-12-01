/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 00:04:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 00:04:58 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

void	light_map(t_map *map, t_point pt, int max, int *limit)
{
	if (pt.x < 0 || pt.y < 0
		|| pt.x >= map->width || pt.y >= map->height)
		return ;
	if (map->map[pt.y][pt.x] == '1' || map->map[pt.y][pt.x] == 'C'
		|| map->map[pt.y][pt.x] == 'E')
		return ;
	if (*limit < max)
		(*limit)++;
	else
		return ;
	map->map[pt.y][pt.x] = 'F';
	light_map(map, (t_point){pt.x, pt.y - 1, 0, 0}, max, limit);
	light_map(map, (t_point){pt.x, pt.y + 1, 0, 0}, max, limit);
	light_map(map, (t_point){pt.x - 1, pt.y, 0, 0}, max, limit);
	light_map(map, (t_point){pt.x + 1, pt.y, 0, 0}, max, limit);
}