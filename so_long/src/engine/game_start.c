/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:10:36 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/20 21:15:31 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <time.h>

// Launches the window, sets the hooks to handle keys and exiting
// and also loads the textures into memory
void	game_init(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->nanoseconds_time = 60000000;
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		(game->map->width * TILE_SIZE), \
		(game->map->height * TILE_SIZE), "so_long");
	if (game->win_ptr == NULL)
		return (free(game->mlx_ptr));
	mlx_hook(game->win_ptr, \
		KeyPress, KeyPressMask, \
		on_keypress, game);
	mlx_hook(game->win_ptr, \
		DestroyNotify, StructureNotifyMask, \
		quit_game, game);
	load_textures(game);
	get_collectibles(game);
	mlx_loop_hook(game->mlx_ptr, run_game, game);
	mlx_loop(game->mlx_ptr);

}

// Runs inside an endless loop
int	run_game(t_data *game)
{
	unsigned long elapsed_nanoseconds;
	static struct timespec last_tick;
	struct timespec current_time;
	struct timespec sleep_time;

	clock_gettime(CLOCK_MONOTONIC, &current_time);
	sleep_time.tv_sec = TICK_CYCLE / 1000000000;
	sleep_time.tv_nsec = TICK_CYCLE % 1000000000;
	// Calculate the elapsed time since the last tick in nanoseconds
	elapsed_nanoseconds = (current_time.tv_sec - last_tick.tv_sec) * 1000000000 +
										(current_time.tv_nsec - last_tick.tv_nsec);
	// This sets the actions within the game ticks
	if (elapsed_nanoseconds >= game->nanoseconds_time)
	{
		if (game->ticks % 5 == 0)
		{
			printf("Frames per tick: %f\n", (double)game->frames / (double)game->ticks);
			printf("Player is at x:%d, y:%d\n", game->map->player->x, game->map->player->y);
		}
		print_player(game, game->img->player, game->map->player->x, game->map->player->y);
		game->ticks++;
		printf("game ticks: %lu\n", game->ticks);
		nanosleep(&sleep_time, NULL);
		clock_gettime(CLOCK_MONOTONIC, &last_tick);
	}
	game->frames++;
	draw_map(game);
	//if (game->ticks == 10)
	//	exit(1);

	return (0);
	/*static clock_t last_tick;
	clock_t current_time;

	last_tick = 0;
	current_time = clock();

	if (current_time - last_tick >= game->microseconds_time)
	{
		if (game->ticks % 5  == 0)
		{
			printf("Player is at x:%d, y:%d\n", game->map->player->x, game->map->player->y);
		}
		game->ticks++;
		printf("game ticks: %lu\n", game->ticks);
		last_tick = current_time;
	}

	draw_map(game);
	if (game->ticks == 10)
		exit(1);

	return (0);*/
}


// Goes through a matrix and sends its position to select the texture to print
void	draw_map(t_data *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
			select_texture(game, x, y);
	}
}

// Selects the texture to print according to the value of the matrix
void	select_texture(t_data *game, int x, int y)
{
	if (game->map->map[y][x] == '1')
		print_texture(game, game->img->walls, x, y);
	else if (game->map->map[y][x] == '0')
		print_texture(game, game->img->floor, x, y);
	/*else if (game->map->map[y][x] == 'C')
		print_texture(game, game->img->collectible, x, y);
	else if (game->map->map[y][x] == 'E')
	{
		if (game->collectibles == NULL)
			print_texture(game, game->img->exit, x, y);
		else
			print_texture(game, game->img->floor, x, y);

	}
	else if (game->map->map[y][x] == 'P')
		print_player(game, game->img->player, x, y);
	*/
}
