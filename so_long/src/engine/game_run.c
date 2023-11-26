/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:38:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/26 16:46:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"
#include "../../inc/engine_utils.h"
#include <time.h>


static t_frame	*find_frame_by_entity(t_list *images, t_entity entity)
{
	t_list	*current;
	t_frame	*frame;

	current = images;
	while (current)
	{
		frame = (t_frame *)current->content;
		if (frame && frame->type == entity)
			return (frame);
		current = current->next;
	}
	return (NULL);
}

static void	draw_background(t_game *game)
{
	t_frame	*floor;
	t_img	*frame;
	int		x;
	int		y;

	floor = find_frame_by_entity(game->images, FLOOR);
	if (floor)
	{
		frame = (t_img *)(ft_lstget(floor->frames, 0))->content;
		if (frame)
		{
			y = -1;
			while (game->map->map[++y])
			{
				x = -1;
				while (game->map->map[y][++x])
				{
					if (game->map->map[y][x])
					{
						mlx_put_image_to_window(frame->win->mlx_ptr,
							frame->win->win_ptr, frame->img_ptr,
							x * SIZE, y * SIZE);
					}
				}
			}
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
