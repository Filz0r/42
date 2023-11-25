/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:38:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/25 16:41:20 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"
#include <time.h>


static t_frame *find_frame_by_entity(t_list *images, t_entity entity)
{
	t_list *current = images;

	while (current)
	{
		t_frame *frame = (t_frame *)current->content;
		if (frame && frame->type == entity)
			return frame;

		current = current->next;
	}

	return NULL;
}

static void	draw_background(t_game *game)
{
	char **map;

	map = game->map->map;
	t_frame *floor = find_frame_by_entity(game->images, FLOOR);
	for (int y = 0; y < game->map->height; y++)
		for(int x = 0; x < game->map->width; x++)
		{
			if (map[y][x])
			{
				mlx_put_image_to_window(game->win->mlx_ptr, game->win->win_ptr, )
			}
		}
}

static int	draw_game(t_game *game)
{
	static struct timespec	last_tick;
	unsigned long			elapsed;
	struct timespec			current;
	struct timespec			sleep_time;

	clock_gettime(CLOCK_MONOTONIC, &current);
	sleep_time.tv_sec = CYCLE / 1000000000;
	sleep_time.tv_nsec = CYCLE % 1000000000;
	elapsed = (current.tv_sec - last_tick.tv_sec) * 1000000000 + (
			current.tv_nsec - last_tick.tv_nsec);
	if (elapsed >= game->ns_time)
	{
		printf("gt: %lu\n", game->tick);
		game->tick++;
		nanosleep(&sleep_time, NULL);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
	}
	draw_background(game);
	printf("fps: %lu\n", game->frames);
	game->frames++;
//	if (game->tick == 1)
//	{
//		exit(1);
		//game_cleanup((void *)game);
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
