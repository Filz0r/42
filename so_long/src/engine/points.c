/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:34:26 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 20:06:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief Creates an memory allocated t_point structure using the map and the
 * char we want to find in the map, this is used in the initial game_init
 * function of the program to determine positions based on a read/search
 * @param map the map where we want to find chars
 * @param to_find the char we want to find in the map.
 * @return if the function fails to find the to_find char inside the map, this
 * function will return NULL, this can also happen if malloc fails, otherwise
 * this function returns an valid pointer to a t_point struct.
 */
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

/**
 * @brief This function is responsible for grabbing an t_point structure that
 * has its relative_x and relative_y values scaled down to a 1:1 scale, however
 * since the relative positions are doubles this results in our relative
 * variables to not be ints anymore, and this function is responsible for
 * converting these values into an truncated int by manually deciding the
 * approximation values with the help of the threshold, basically if the
 * values saved inside the t_point structure are greater than the values after
 * the 0 in threshold its going to put that int into a greater value, otherwise
 * it sets the int to the values, check the notes for more info on this
 * @param point a t_point structure containing the values we want to convert
 * @param threshold_x the threshold we can scale up to relative to x
 * @param threshold_y the threshold we can scale up to relative to y
 * @return returns a converted point
 *
 * NOTES: For an visual representation of how we normalize the points,
 * lets say our point variable contains the following values
 * { 224, 68, 9.125, 3.85 } and a x treshold of 0.05 and an y threshold of 0.75
 * this function will convert the 9.125 to 9 and the 3.85 to 4.
 */
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

/**
 * @brief This function works in a manner similar to the normalize point,
 * however instead of converting the values up and down, we basically add
 * our target and current positions together, and multiply that value with
 * the factor and we then remove the current and target positions this results
 * in we moving to an point greater than our target point, its safe to ignore
 * the narrowing conversion warnings in this function because the values we
 * are multiplying are ints, meaning that we basically scale up our positioning.
 * @param current a t_point that contains the current player position.
 * @param target a t_point that contains the target position we want to move
 * the player into.
 * @param factor a floating point number that is multiplied by our positions
 * as a way to scale up the target position to a value that is factor % greater
 * than the original target positions.
 * @return returns an scaled up t_point structure.
 */
t_point	interpolate_point(t_point current, t_point target, double factor)
{
	return ((t_point){current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y),
		current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y)});
}

/**
 * @brief Scales up the passed t_point structure using the SIZE macro
 * @param pt the point we want to scale up
 * @return an scaled up point
 *
 * NOTE: if this was C++, we would overload this but as this is plain old C
 * we need to define a new function.
 */
t_point	scale_up(t_point pt)
{
	return ((t_point){pt.x * SIZE, pt.y * SIZE, pt.x * SIZE, pt.y * SIZE});
}

/**
 * @brief creates an stack allocated pointer of the given t_point structure
 * @param pt a t_point struct we want to allocate to memory
 * @return Either returns NULL if malloc fails or an valid pointer to
 * a t_point structure.
 */
t_point	*new_point(t_point pt)
{
	t_point	*res;

	res = malloc(sizeof(t_point));
	if (!res)
		return (NULL);
	*res = pt;
	return (res);
}
