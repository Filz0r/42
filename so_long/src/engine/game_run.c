/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:38:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 21:45:48 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

static int	draw_game(t_game *game)
{
	static struct timespec	last_tick;
	unsigned long			elapsed;
	struct timespec			current;

	clock_gettime(CLOCK_MONOTONIC, &current);
	elapsed = (current.tv_sec - last_tick.tv_sec) * game->ns_time + (
			current.tv_nsec - last_tick.tv_nsec);
	if (elapsed >= game->ns_time)
	{
//		will_raise_fire(game, 1);
		render_frame(game, game->current);
//		print_time_status(game, &last_tick);
//		nanosleep(&(game->sleep_time), NULL);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
		game->tick++;
		if (game->tick % 10 == 0)
		{
			will_raise_fire(game);
			game->kill_scale = game->kill_scale * 2;
		}
	}
	if (game->current == PLAYER_WALKING)
	{
		game->last = game->current;
		game->current = PLAYER_IDLE;
	}
	return (0);
}

void	*game_run(void *ptr, char *name)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (game)
	{
		game->win = new_window(game->map->width, game->map->height, name);
		if (!(game->win))
			return (game_cleanup(ptr));
		game->images = NULL;
		load_assets(game->win, &(game->images));
		if (!(game->images))
			return (game_cleanup(game));
		game->overlay = create_overlay(game->win);
		game->last = PLAYER_IDLE;
		game->current = PLAYER_IDLE;
		render_frame(game, game->current);
		mlx_hook(game->win->win_ptr, DestroyNotify, \
		StructureNotifyMask, quit_game, game);
		mlx_hook(game->win->win_ptr, KeyRelease, \
		KeyReleaseMask, on_key, game);
		mlx_loop_hook(game->win->mlx_ptr, draw_game, game);
		mlx_loop(game->win->mlx_ptr);
	}
	return ((void *)0);
}
