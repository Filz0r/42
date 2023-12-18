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

/**
 * @brief Function used to quit the game when we are first initializing the
 * mlx pointers, its only called when theres an error initializing mlx stuff
 * @param ptr an valid t_game pointer
 * @return NULL
 */
void	*game_cleanup(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (!game)
		exit(EXIT_FAILURE);
	quit_game(game, EXIT_FAILURE);
	return (NULL);
}

/**
 * @brief function that cleans all of the allocated memory and exits the game
 * @param game the t_game pointer containing all of the data
 * @param signal the exit code of the program, either 1 or 0 in most cases
 * @return value passed by signal
 */
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
		if (game->tiles_to_flood)
			free_queue(game->tiles_to_flood);
		if (game->flooded_tiles)
			ft_lstclear(&(game->flooded_tiles), free);
	}
	free(game);
	exit(signal);
}
