/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:23:09 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/29 12:52:23 by fparreir         ###   ########.fr       */
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
		if (game->overlay)
			destroy_image(game->overlay);
		if (game->images)
			images_cleanup(game->images);
		if (game->win)
			window_cleanup(game->win);
	}
	return (NULL);
}
