/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/28 19:07:48 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

void	move_player(t_game *game, int action)
{
	if (action == UP)
		check_collision(game, game->map->player->x,
			game->map->player->y - 2, action);
	else if (action == DOWN)
		check_collision(game, game->map->player->x,
			game->map->player->y + 2, action);
	else if (action == LEFT)
		check_collision(game, game->map->player->x - 2,
			game->map->player->y, action);
	else if (action == RIGHT)
		check_collision(game, game->map->player->x + 2,
			game->map->player->y, action);
	game->current = PLAYER_WALKING;
	render_frame(game, game->current);
}

void	check_collision(t_game *g, int x, int y, int action)
{
	t_point	check;
	t_point	norm_check;
	t_map	*m;
	int		wall_x;
	int		wall_y;

	m = g->map;
	printf("before: { x: %d, y: %d }\n",
		   g->map->player->x, g->map->player->y);
	check = (t_point){x, y,
		((double)x / SIZE), ((double)y / SIZE)};
	if (action == DOWN)
		norm_check = normalize_point(check, 0.45, 0.10);
	else if (action == UP)
		norm_check = normalize_point(check, 0.45, 0.75);
	if (m->map[norm_check.y][norm_check.x] == '1')
	{
		wall_x = norm_check.x * SIZE;
		wall_y = norm_check.y * SIZE;
		if ((x + SIZE >= wall_x
				|| x <= wall_x + SIZE)
			|| (y + SIZE >= wall_y
				|| y <= wall_y + SIZE))
			return ;
	}
	g->map->player->x = x;
	g->map->player->y = y;
	g->map->player->relative_x = x;
	g->map->player->relative_y = y;
	printf("after: { x: %d, y: %d }\n",
		   g->map->player->x, g->map->player->y);
}

int	will_collide(t_game *g, t_point going_to)
{
	int	x;
	int	y;

	x = normalize_point(going_to, 0.5, 0).relative_x;
	y = normalize_point(going_to, 0.5, 0).relative_y;
	if (g->map->map[y][x] == '1')
		return (1);
	x = normalize_point(going_to, 0.5, 2).relative_x;
	y = normalize_point(going_to, 0.5, 2).relative_y;
	if (g->map->map[y][x] == 'E')
		return (2);
	else if (g->map->map[y][x] == 'C')
		return (3);
	else if (g->map->map[y][x] == 'F')
		return (4);
	return (0);
}

