/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:34:26 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 22:30:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

//Todo:docs

// Finds the to_find in the map and allocates it to memory
// and returns it as t_point *, returns NULL if it isn't
// found or if malloc fails.
t_point	*create_point(char **map, char to_find)
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

t_point	normalize_point(t_point point,
	double threshold_x, double threshold_y)
{
	return ((t_point){
		normalize(point.relative_x, threshold_x),
		normalize(point.relative_y, threshold_y),
		point.relative_x,
		point.relative_y
	});
}

t_point	interpolate_point(t_point current, t_point target, double factor)
{
	return ((t_point){current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y),
		current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y)});
}

t_point	scale_up(t_point pt)
{
	return ((t_point){pt.x * SIZE, pt.y * SIZE, pt.x * SIZE, pt.y * SIZE});
}

t_point	get_point(char **map, char to_find)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == to_find)
				return ((t_point){x, y, x, y});
		}
	}
	return ((t_point){-1, -1, -1, -1});
}