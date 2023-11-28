/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 22:52:10 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

int	on_keypress(int keysym, t_game *game)
{
	printf("pressed: %d\n", keysym);
	if (keysym == XK_a || keysym == XK_Left)
		move_player(game, LEFT);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player(game, DOWN);
	else if (keysym == XK_d || keysym == XK_Right)
		move_player(game, RIGHT);
	else if (keysym == XK_w || keysym == XK_Up)
		move_player(game, UP);
//	if (keysym == XK_Escape)
//		quit_game(game);
	return (1);
}

void	move_player(t_game *game, int action)
{
	if (action == UP)
		handle_movement(game, game->map->player->x,
			game->map->player->y - 1, UP);
	else if (action == DOWN)
		handle_movement(game, game->map->player->x,
			game->map->player->y + 1, DOWN);
	else if (action == LEFT)
		handle_movement(game, game->map->player->x - 1,
			game->map->player->y, LEFT);
	else if (action == RIGHT)
		handle_movement(game, game->map->player->x + 1,
			game->map->player->y, RIGHT);
	game->current = PLAYER_WALKING;
	render_frame(game, game->current);
}

void	handle_movement(t_game *g, int x, int y, int action)
{
	int	signal;

	signal = 0;
	move_on_map(g, &signal, x / SIZE, y / SIZE);
	if (signal == 1)
		return ;
	if (action == UP)
		g->map->player->y -= SIZE / 4;
	else if (action == DOWN)
		g->map->player->y += SIZE / 4;
	else if (action == LEFT)
		g->map->player->x -= SIZE / 4;
	else if (action == RIGHT)
		g->map->player->x += SIZE / 4;
	g->player->target = (t_rpoint)
	{(float)g->player->current->x, (float)g->player->current->y};
}

void	move_on_map(t_game *g, int *signal, int x, int y)
{
	float	target_x;
	float	target_y;
	int		target_tile_x;
	int		target_tile_y;

	if (x < 0 || y < 0 || x >= g->win->width || y >= g->win->height)
	{
		*signal = 1;
		return ;
	}
	target_x = g->player->target.x;
	target_y = g->player->target.y;
	target_tile_x = target_x / SIZE;
	target_tile_y = target_y / SIZE;
	if (g->map->map[target_tile_y][target_tile_x] == '1')
	{
		if (target_x >= 0 && target_x < g->win->width
			&& target_y >= 0 && target_y < g->win->height)
		{
			if (target_x < g->player->current->x)
				target_x = target_tile_x * SIZE + SIZE / 4;
			else if (target_x > g->player->current->x)
				target_x = (target_tile_x + 1) * SIZE - SIZE / 4;
			if (target_y < g->player->current->y)
				target_y = target_tile_y * SIZE + SIZE / 4;
			else if (target_y > g->player->current->y)
				target_y = (target_tile_y + 1) * SIZE - SIZE / 4;
		}
	}
	if (g->map->map[target_tile_y][target_tile_x] == 'E')
	{
		*signal = 1;
		return ;
	}
	if (g->map->map[y][x] == 'C')
	{
		g->map->map[y][x] = 'P';
		g->map->map[g->map->player->y / SIZE][g->map->player->x / SIZE] = '0';
//		remove_collectible(g,x, y);
	}
//	else
//		handle_end(g, x, y);
}
