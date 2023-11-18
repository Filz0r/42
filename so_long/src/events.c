/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 18:08:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/18 12:13:35 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	on_destroy(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return (0);
}

int	on_keypress(int keysym, t_data *game)
{
	printf("pressed: %d\n", keysym);
	if (keysym == XK_Escape)
		quit_game(game);
	return (0);
}

int	quit_game(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game);
	exit(1);
}

void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->img->addr + \
	(y * game->img->line_length + x * (game->img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
