/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:38:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/26 17:58:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"

static void	draw_background(t_game *game)
{
	t_frame	*floor;
	t_img	*frame;
	int		x;
	int		y;

	floor = find_frame_by_entity(game->images, FLOOR);
	frame = (t_img *)(ft_lstget(floor->frames, 0))->content;
	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (frame->img_ptr && frame->win->mlx_ptr && frame->win->win_ptr)
				mlx_put_image_to_window(frame->win->mlx_ptr,
					frame->win->win_ptr, frame->img_ptr,
					x * SIZE, y * SIZE);
		}
	}
}

static int	draw_game(t_game *game)
{
	static struct timespec	last_tick;
	unsigned long			elapsed;
	struct timespec			current;

	draw_background(game);
	clock_gettime(CLOCK_MONOTONIC, &current);
	elapsed = (current.tv_sec - last_tick.tv_sec) * 1000000000 + (
			current.tv_nsec - last_tick.tv_nsec);
	if (elapsed >= game->ns_time)
	{
		printf("gt: %lu\n", game->tick);
		nanosleep(&(game->sleep_time), NULL);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
		game->tick++;
	}
	game->frames++;
//	if (game->tick == 1)
//	{
//		exit(1);
////		game_cleanup((void *)game);
//	}
	return (0);
}


void	game_run(void *ptr)
{
	t_game	*game;

	game = (t_game *)ptr;
	if (game)
	{
		mlx_loop_hook(game->win->mlx_ptr, draw_game, game);
		mlx_loop(game->win->mlx_ptr);
	}
}
