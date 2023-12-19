/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:09:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/19 18:05:12 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

/**
 * @brief Initializes the counters/static variables of the t_game structures,
 * and at the same time creates and populates the t_map struct and fills
 * everything else with 0's (ft_memset)
 * @param map a valid char ** that passes the parameters required in the
 * subject
 * @return returns a pointer to the initial t_game struct that will be used
 * to launch mlx
 */
void	*game_init(char **map)
{
	t_game	*ptr;

	ptr = malloc(sizeof(t_game));
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, sizeof(t_game));
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
