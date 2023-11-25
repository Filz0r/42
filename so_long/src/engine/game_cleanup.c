/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:23:09 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/25 10:33:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

void	*game_cleanup(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (game)
	{
		if (game->map)
			map_cleanup(game->map);
		if (game->images)
			images_cleanup(game->images);
		if (game->player)
			player_cleanup(game);
		if (game->win)
			window_cleanup(game->win);
	}
	return (NULL);
}
