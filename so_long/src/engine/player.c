/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:52:23 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 15:23:50 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

t_player	*load_player(t_game *ptr)
{
	t_player	*res;

	res = malloc(sizeof(t_player));
	if (!res)
		return (NULL);
	res->start = *(ptr->map->start);
	res->current = ptr->map->player;
	res->target = (t_rpoint){-1, -1};
	res->smooth = (t_rpoint){(float)res->current->x,
		(float)res->current->y};
	return (res);
}

void	*player_cleanup(t_game *game)
{
	if (game->player)
	{
		if (game->map)
			if (game->player->current)
				map_cleanup(game->map);
		free(game->player);
		game->player = NULL;
	}
	return (NULL);
}
