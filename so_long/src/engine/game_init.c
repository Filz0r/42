/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:09:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/25 13:56:22 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

//todo: Protect the pointers for null;
void	*game_init(char **map, const char *name)
{
	t_game	*ptr;

	ptr = malloc(sizeof(t_game));
	if (!ptr)
		return (NULL);
	ptr->map = load_map(map);
	if (!(ptr->map))
		return (game_cleanup(ptr));
	ptr->win = new_window(ptr->map->width,
			ptr->map->height, (char *)name);
	if (!(ptr->win))
		return (game_cleanup(ptr));
	ptr->images = NULL;
	load_assets(ptr->win, &(ptr->images));
	if (!(ptr->images))
		return (game_cleanup(ptr));
	ptr->player = load_player(ptr);
	if (!(ptr->player))
		return (game_cleanup(ptr));
	ptr->tick = 0;
	ptr->frames = 0;
	ptr->ns_time = 200000000;
	ptr->sleep_time = (struct timespec){CYCLE / 1000000000,
		CYCLE % 1000000000};
	return (ptr);
}
