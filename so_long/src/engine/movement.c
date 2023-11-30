/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 19:41:34 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

int	move_player(t_game *game, int action)
{
	if (action == UP)
		return (check_collision(game, game->map->player->x,
				game->map->player->y - 8, action));
	else if (action == DOWN)
		return (check_collision(game, game->map->player->x,
				game->map->player->y + 8, action));
	else if (action == LEFT)
		return (check_collision(game, game->map->player->x - 8,
				game->map->player->y, action));
	else
		return (check_collision(game, game->map->player->x + 8,
				game->map->player->y, action));
//	nanosleep(&(game->sleep_time), NULL);
}

int	check_collision(t_game *g, int x, int y, int action)
{
	t_point	check;
	t_point	norm_check;

	g->current = PLAYER_WALKING;
	check = (t_point){x, y,
		((double)x / SIZE), ((double)y / SIZE)};
	if (action == DOWN)
		norm_check = normalize_point(check, 0.375, 0.10);
	else if (action == LEFT)
		norm_check = normalize_point(check, 0.3515, 0.45);
	else if (action == RIGHT)
		norm_check = normalize_point(check, 0.725, 0.45);
	else
		norm_check = normalize_point(check, 0.375, 0.55);
	if (action == RIGHT)
		g->mirror = 0;
	else if (action == LEFT)
		g->mirror = 1;
	handle_restof_movement(g, norm_check, x, y);
	return (1);
}

void	handle_restof_movement(t_game *g, t_point norm_point, int x, int y)
{
	t_point	interpolated;

	interpolated = interpolate_point(*(g->map->player),
			(t_point){x, y, x, y}, 0.3);
	if (g->map->map[norm_point.y][norm_point.x] == '1')
		return ;
	else if (g->map->map[norm_point.y][norm_point.x] == 'C')
		remove_collectible(g, norm_point);
	else if (g->map->map[norm_point.y][norm_point.x] == 'E'
		&& g->map->collectibles == NULL)
		quit_game(g);
	g->moves++;
	*(g->map->player) = interpolated;
	render_frame(g, g->current);
}
