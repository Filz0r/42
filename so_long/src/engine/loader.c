/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:42 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 19:50:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief creates the t_map structure that contains the initial
 * data needed to create the frames after the window is open.
 * @param map an valid char ** map that we can draw with
 * @return either returns NULL if malloc fails or a pointer to the
 * valid t_map struct that we can use.
 */
t_map	*load_map(char **map)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	ft_memset(res, 0, sizeof(t_map));
	res->map = map;
	res->collectibles = NULL;
	res->height = get_map_height(map);
	res->width = get_map_width(map);
	res->player = create_point(map, 'P');
	if (!(res->player))
		return (map_cleanup(res));
	res->start = *(res->player);
	*(res->player) = scale_up(*(res->player));
	res->exit = create_point(map, 'E');
	*(res->exit) = scale_up(*(res->exit));
	if (!(res->exit))
		return (map_cleanup(res));
	get_collectibles(map, &(res->collectibles));
	if (res->collectibles == NULL)
		return (map_cleanup(res));
	res->col_count = ft_lstsize(res->collectibles);
	return (res);
}

/**
 * @brief loads the assets that are defined in the path into a linked
 * list that will contain all of the mlx_images we will need to draw on
 * the game window
 * @param win a pointer to the t_window with all the mlx stuff we need
 * @param lst a reference to the linked list stored in t_game that contains
 * every single mlx image and in their respective type with animations
 * included.
 */
void	load_assets(t_window *win, t_list **lst)
{
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, FLOOR_PATH, FLOOR, 1)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, EXIT_PATH, EXIT, 1)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, COLL_PATH, COLLECTIBLE, 1)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, WALL_PATH, WALL, 1)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, IDLE_PATH, PLAYER_IDLE, 4)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, WALK_PATH, PLAYER_WALKING, 4)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, DIE_PATH, PLAYER_DYING, 3)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, DIGIT_PATH, DIGITS, 10)));
	ft_lstadd_back(lst,
		ft_lstnew(create_frame(win, ENEMY_PATH, ENEMY, 4)));
}
