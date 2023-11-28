/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/28 20:25:28 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

void	move_player(t_game *game, int action)
{
	if (action == UP)
		check_collision(game, game->map->player->x,
			game->map->player->y - 4, action);
	else if (action == DOWN)
		check_collision(game, game->map->player->x,
			game->map->player->y + 4, action);
	else if (action == LEFT)
		check_collision(game, game->map->player->x - 4,
			game->map->player->y, action);
	else if (action == RIGHT)
		check_collision(game, game->map->player->x + 4,
			game->map->player->y, action);
	game->current = PLAYER_WALKING;
	render_frame(game, game->current);
}

void	check_collision(t_game *g, int x, int y, int action)
{
	t_point	check;
	t_point	norm_check;
	int		wall_x;
	int		wall_y;

	check = (t_point){x, y,
		((double)x / SIZE), ((double)y / SIZE)};
	if (action == DOWN)
		norm_check = normalize_point(check, 0.45, 0.10);
	else if (action == LEFT)
		norm_check = normalize_point(check, 0.575, 0.75);
	else
		norm_check = normalize_point(check, 0.45, 0.75);
	if (g->map->map[norm_check.y][norm_check.x] == '1')
	{
		wall_x = norm_check.x * SIZE;
		wall_y = norm_check.y * SIZE;
		if ((x + SIZE >= wall_x
				|| x <= wall_x + SIZE)
			|| (y + SIZE >= wall_y
				|| y <= wall_y + SIZE))
			return ;
	}
	handle_restof_movement(g, norm_check, x, y);
}

void	handle_restof_movement(t_game *g, t_point norm_point, int x, int y)
{
//	if (g->map->map[norm_point.y][norm_point.x] == 'C')
	(void)norm_point;
	*(g->map->player) = (t_point){x, y, (double)x, (double)y};
}
