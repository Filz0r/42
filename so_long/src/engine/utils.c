/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:38:14 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 11:58:23 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief this function is used to manually decide the given value we want to
 * approximate, or not, to an int.
 * @param nb the number we want to try to approximate up or down.
 * @param threshold the threshold of approximation we want to allow.
 * @return an approximated/normalized int.
 *
 * NOTES: just like I did for the normalize_point function I'm going to give an
 * 'graphical representation of how this function works. Lets say nb is 9.125
 * and our threshold is 0.25, we first cast nb into an in so that the compiler
 * truncates our double, then we check if the given number is greater than
 * the sum of threshold and the truncated int, if it is we return that
 * truncated value plus one, otherwise we only return the truncated value.
 */
int	normalize(double nb, double threshold)
{
	int	res;

	res = (int)nb;
	if (nb > res + threshold)
		return (res + 1);
	else
		return (res);
}

/**
 * @brief Finds a pointer to a t_frame inside a linked list containing the
 * given entity.
 * @param lst The list we want to search in
 * @param entity the entity/type of object we want to look for.
 * @return returns NULL if the given entity isn't found on the given list,
 * otherwise it returns a t_frame pointer of the element we are looking for.
 */
t_frame	*find_frame_by_entity(t_list *lst, t_entity entity)
{
	t_list	*current;
	t_frame	*frame;

	current = lst;
	while (current)
	{
		frame = (t_frame *)current->content;
		if (frame && frame->type == entity)
			return (frame);
		current = current->next;
	}
	return (NULL);
}

/**
 * @brief Finds an t_img pointer with the given entity, its mainly used to
 * grab assets that aren't animated from memory, we first call
 * find_frame_by_entity to get a t_frame pointer that contains all the t_img
 * for the given entity, then we return the first t_img of the given entity
 * @param lst the linked list we want to search in.
 * @param entity the entity we are looking for.
 * @return returns NULL if find_frame_by_entity or ft_lstget fail, otherwise
 * it returns a valid t_img pointer that can be used to draw on the screen.
 */
t_img	*get_img_by_entity(t_list *lst, t_entity entity)
{
	t_frame	*frame;
	t_img	*img;

	frame = find_frame_by_entity(lst, entity);
	if (!frame)
		return (NULL);
	img = (t_img *)((ft_lstget(frame->frames, 0))->content);
	if (!img)
		return (NULL);
	return (img);
}

/**
 * @brief Goes trough the given map counting how many tiles inside the map
 * aren't an '1', and then returns the calculated value.
 * @param map the map we want to search
 * @return it always returns an integer, if there are no tiles to fill it
 * will return 0, otherwise it will return the number of tiles we can fill.
 */
int	count_fillable_tiles(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (map[++y] != 0)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				continue ;
			else
				count++;
		}
	}
	return (count);
}

/**
 * @brief clones the char ** array that contains the map of the game into
 * a temporary pointer that can be manipulated and altered for various
 * mechanics of the game, without ever manipulating the original map.
 * @param t_map the t_map structure that contains the map we want to clone
 * @return Can return NULL if malloc fails, if ft_strdup fails, but malloc
 * doesn't you can bet your ass that this function is going to return
 * an array of NULL pointers, otherwise it returns a clone of the map saved
 * inside t_map.
 */
char	**map_clone(t_map *map)
{
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!res)
		return (NULL);
	k = -1;
	while (map->map[++k])
		res[k] = ft_strdup(map->map[k]);
	res[k] = 0;
	return (res);
}
