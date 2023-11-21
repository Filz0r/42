/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:26:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 16:26:58 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"


void	print_player(t_data *game, t_list *start, int x, int y)
{
	t_list	*temp;

	temp = start;
	while (temp)
	{
		print_texture(game, temp->content, x, y);
		temp = temp->next;
	}

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
	game->img->exit = mlx_xpm_file_to_image
			(game->mlx_ptr, EXIT, \
		&size, &size);
	load_player_textures(game);

}
// Loads the textures of the player into a linked list
void	load_player_textures(t_data *game)
{
	int 	i;
	int 	size;
	char	*temp;
	t_list	*player;

	i = 0;
	temp = NULL;
	player = NULL;
	size = TILE_SIZE;
	while (i < 4)
	{
		temp = generate_player_path(i);
		ft_lstadd_back(&player, ft_lstnew(mlx_xpm_file_to_image(game->mlx_ptr, \
						temp, &size, \
						&size)));
		free(temp);
		i++;
	}
	game->img->player = player;
}
