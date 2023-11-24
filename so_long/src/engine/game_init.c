/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:09:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 14:19:36 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"

// Protect the pointers for null;
void	*game_init(char **map, const char *name)
{
	t_game	*ptr;

	ptr = malloc(sizeof(t_game));
	if (!ptr)
		return (NULL);
	ptr->map = load_map(map);
	if (!(ptr->map))
		return (game_cleanup(ptr));
	ptr->win = new_window(ptr->map->width, ptr->map->height, (char *)name);
	if (!(ptr->win))
		return (game_cleanup(ptr));
	ptr->images = NULL;
	load_assets(ptr->win, &(ptr->images));
	if (!(ptr->images))
		return (game_cleanup(ptr));
	ptr->player = load_player(ptr);
	ptr->tick = 0;
	ptr->frames = 0;
	ptr->ns_time = 6000000000;
	return (ptr);
}

void	*game_cleanup(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (!game)
		return (NULL);
	if (game->map)
		return (map_cleanup(game->map));
	if (game->win)
		return (window_cleanup(game->win));
	if (game->images)
		return (images_cleanup(game->images));
	return (NULL);
}
