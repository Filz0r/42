/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:10:36 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/19 19:27:39 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// Launches the window, sets the hooks to handle keys and exiting
// and also loads the textures into memory
void	game_init(t_data *game)
{
	game->mlx_ptr = mlx_init();
	game->redraw = 1;
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		(game->map->width * TILE_SIZE), \
		(game->map->height * TILE_SIZE), "so_long");
	if (game->win_ptr == NULL)
		return (free(game->mlx_ptr));
	mlx_hook(game->win_ptr, \
		KeyPress, KeyPressMask,\
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
	/*
	static unsigned long counter;
	static unsigned long last_count;
	unsigned long current;
	unsigned long elapsed;

	counter = *(game->count);
	last_count = *(game->count) - 1;
	current = counter * CYCLE_SIZE / FPS;
	elapsed = current - last_count;

	if (elapsed < CYCLE_SIZE/ FPS)
	{
		ft_usleep((CYCLE_SIZE / (FPS - elapsed)));
		current = counter * CYCLE_SIZE / FPS;
	}

	last_count = current;
*/
	//game->frames++;
	draw_map(game);
	/*if (counter % FPS == 0 && elapsed > 0)
	{
		//print_player(game, game->img->player, game->map->player->x, game->map->player->y);
		//printf("FPS: %lu\n", counter / (elapsed / 1000000));
	}

	//ft_printf("count: %d\n", (int)counter);
	(*(game->count))++;
	if (game->frames == FPS * 100)
	{
		ft_printf("%d frames cycled", game->frames);
		exit(1);
	}*/
	return (0);
}

void	ft_usleep(unsigned int microseconds)
{
	unsigned long target;
	unsigned long current;
	unsigned long curr;

	current = LONG_MIN;
	target = (unsigned long)microseconds * CYCLE_SIZE;
	while (LONG_MAX > current)
	{
		curr = INT_MIN;
		while (curr < target)
		{
			recursive_workload(INT_MAX);
			curr++;
		}
		recursive_workload(INT_MAX);
		current++;
	}
}


void	recursive_workload(int count)
{
	if (count == INT_MIN)
		return ;

	unsigned long target;
	unsigned long current;
	unsigned long curr;

	current = LONG_MIN;
	target = LONG_MAX;
	while (current > target)
	{
		curr = LONG_MIN;
		while (target < curr)
		{
			recursive_workload(count - 1);
			curr++;
		}
		current++;
	}
	recursive_workload(count - 1);
}

// Goes through a matrix and sends its position to select the texture to print
void	draw_map(t_data *game)
{
	int x;
	int y;

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
	else if (game->map->map[y][x] == 'C')
		print_texture(game, game->img->collectible, x, y);
	else if (game->map->map[y][x] == 'E')
	{
		if (game->collectibles == NULL)
			print_texture(game, game->img->collectible, x, y);
		else
			print_texture(game, game->img->floor, x, y);

	}
	else if (game->map->map[y][x] == 'P')
		print_player(game, game->img->player, x, y);

}

void	print_player(t_data *game, t_list *start, int x, int y)
{
	t_list	*temp;
	//static int counter;
	//static int delay;

	temp = start;
	//counter = 0;
	//delay = 10;
	while (temp)
	{
		//ft_usleep((unsigned int)game->microseconds_time * 10);
		//if (counter % delay == 0)
		//{
			print_texture(game, temp->content, x, y);
			temp = temp->next;
		//}

	}
	//counter++;
}

// Prints the *img ptr into the coords x and y of the window
void	print_texture(t_data *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,img, \
							x * TILE_SIZE, y * TILE_SIZE);

}

// Loads the textures into memory
void	load_textures(t_data *game)
{
	int size;

	size = TILE_SIZE;
	game->img->floor = mlx_xpm_file_to_image(game->mlx_ptr, FLOOR_PATH, \
		&size, &size);
	game->img->walls = mlx_xpm_file_to_image(game->mlx_ptr, WALL_PATH, \
		&size, &size);
	game->img->collectible = mlx_xpm_file_to_image
			(game->mlx_ptr, COLLECTIBLE, \
			&size, &size);
	load_player_textures(game);

}
// Loads the textures of the player into a linked list
void	load_player_textures(t_data *game)
{
	int 	i;
	int 	size;
	t_list	*player;
	char	*temp;

	i = 0;
	temp = NULL;
	player = NULL;
	size = TILE_SIZE;
	while (i < 4)
	{
		temp = generate_player_path(i++);
		ft_lstadd_back(&player, ft_lstnew(mlx_xpm_file_to_image(game->mlx_ptr, \
						temp, &size, \
						&size)));
		free(temp);
	}
	game->img->player = player;
}



/*if (game->redraw == 1)
{
	get_collectibles(game);
	put_collectibles(game);
	game->redraw = 0;
}*/

void	put_collectibles(t_data *game)
{
	int size;
	t_list *temp;

	size = TILE_SIZE;
	temp = game->collectibles;
	game->img->collectible = mlx_xpm_file_to_image(game->mlx_ptr, COLLECTIBLE, &size, &size);
	while (temp)
	{
		mlx_put_image_to_window(game->mlx_ptr, \
            game->win_ptr, \
            game->img->collectible, \
            ((t_point *) temp->content)->x * TILE_SIZE, \
            ((t_point *) temp->content)->y * TILE_SIZE);
		temp = temp->next;
	}

}