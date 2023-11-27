/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:38:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 15:56:32 by fparreir         ###   ########.fr       */
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
	elapsed = (current.tv_sec - last_tick.tv_sec) * 1000000000 + (
			current.tv_nsec - last_tick.tv_nsec);
	render_frame(game);
	if (elapsed >= game->ns_time)
	{
		printf("gt: %lu\n", game->tick);
		nanosleep(&(game->sleep_time), NULL);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
		game->tick++;
	}
	game->frames++;//This has to be deleted for delivery
//	if (game->tick == 20)
//	{
//		exit(1);
//		game_cleanup((void *)game);
//	}
	return (0);
}

void	game_run(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (game)
	{
		game->treshold = (double)SIZE / 0.75;
		game->overlay = create_overlay(game->win);
		render_frame(game);
		mlx_hook(game->win->win_ptr, KeyPress, KeyPressMask, on_keypress, game);
		mlx_loop_hook(game->win->mlx_ptr, draw_game, game);
		mlx_loop(game->win->mlx_ptr);
	}
}
