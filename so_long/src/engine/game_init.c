/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:09:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 17:37:35 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

//todo: docs;
void	*game_init(char **map)
{
	t_game	*ptr;

	ptr = malloc(sizeof(t_game));
	ft_memset(ptr, 0, sizeof(t_game));
	if (!ptr)
		return (NULL);
	ptr->map = load_map(map);
	if (!(ptr->map))
		return (game_cleanup(ptr));
	ptr->mirror = 0;
	ptr->tick = 0;
	ptr->moves = 0;
	ptr->kill_scale = 1;
	ptr->frames = 0;
	ptr->last = PLAYER_IDLE;
	ptr->current = PLAYER_IDLE;
	ptr->ns_time = SECOND - CYCLE;
	ptr->images = NULL;
	return (ptr);
}
