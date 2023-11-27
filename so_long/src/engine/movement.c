/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:16:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 17:16:41 by fparreir         ###   ########.fr       */
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
}

void	handle_movement(t_game *g, int x, int y, int action)
{
	int	signal;

	signal = 0;
	move_on_map(g, &signal, x / SIZE, y / SIZE);
	if (signal == 1)
		return ;
	if (action == UP)
		g->map->player->y -= 16;
	else if (action == DOWN)
		g->map->player->y += 16;
	else if (action == LEFT)
		g->map->player->x -= 16;
	else if (action == RIGHT)
		g->map->player->x += 16;
	g->player->target = (t_rpoint)
	{(float)g->player->current->x, (float)g->player->current->y};
}

void	move_on_map(t_game *g, int *signal, int x, int y)
{
	if (x < 0 || y < 0)
	{
		*signal = 1;
		return ;
	}
	if (g->map->map[y][x] == '0')
	{
		g->map->map[y][x] = 'P';
		g->map->map[g->map->player->y / SIZE][g->map->player->x / SIZE] = '0';
	}
	else if (g->map->map[y][x] == '1')
	{
		*signal = 1;
		return ;
	}
	else if (g->map->map[y][x] == 'C')
	{
		g->map->map[y][x] = 'P';
		g->map->map[g->map->player->y / SIZE][g->map->player->x / SIZE] = '0';
//		remove_collectible(g,x, y);
	}
//	else
//		handle_end(g, x, y);
}
