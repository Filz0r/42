/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 10:10:36 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/18 11:00:27 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	game_init(t_data *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return ;
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
		(game->map->width * TILE_SIZE), \
		(game->map->height * TILE_SIZE), "so_long");
	if (game->win_ptr == NULL)
		return (free(game->mlx_ptr));
	mlx_hook(game->win_ptr, KeyRelease, \
		KeyReleaseMask, on_keypress, game);
	mlx_hook(game->win_ptr, \
	DestroyNotify, StructureNotifyMask, \
	quit_game, game);

	mlx_loop(game->mlx_ptr);
}

//mlx_hook(game->win_ptr, KeyPress, KeyPressMask, quit_game, game);

/*game->img->img = mlx_xpm_file_to_image(game->mlx_ptr, \
	WALL_PATH, &game->img->width, &game->img->height);

mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->img->img, 0, 0);
*/