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

static void	set_kill_scale(t_game *g)
{
	will_raise_fire(g);
	if (FLOOD_MAX != -1)
	{
		if (g->kill_scale < FLOOD_MAX)
			g->kill_scale += FLOOD_SCALE;
		else
			g->kill_scale = 1;
	}
	else
		g->kill_scale += FLOOD_SCALE;
}

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
		render_frame(game, game->current);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
		game->tick++;
		if (game->tick % 10 == 0)
			set_kill_scale(game);
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
		load_assets(game->win, &(game->images));
		if (!(game->images))
			return (game_cleanup(game));
		game->overlay = create_overlay(game->win);
		game->tiles_to_flood = create_queue(
				count_fillable_tiles(game->map->map));
		light_map(game->map, game->map->start, game->tiles_to_flood);
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
