/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_cleanup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:23:09 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 22:23:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

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
