/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:23:09 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 21:45:17 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

// TODO: DOCUMENTATION
void	*game_cleanup(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (!game)
		exit(EXIT_FAILURE);
	quit_game(game, EXIT_FAILURE);
	return (NULL);
}

int	quit_game(t_game *game, int signal)
{
	int	i;

	i = 0;
	if (game)
	{
		while (game->map->map[i] != 0)
			free(game->map->map[i++]);
		free(game->map->map);
		if (game->map)
			map_cleanup(game->map);
		if (game->overlay)
			destroy_image(game->overlay);
		if (game->images)
			images_cleanup(game->images);
		if (game->win)
			window_cleanup(game->win);
	}
	free(game);
	exit(signal);
}
