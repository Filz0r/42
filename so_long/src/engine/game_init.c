/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:33:17 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 17:40:47 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/engine.h"

void	*game_init(char **map, char *name)
{
	//t_game	*game;
	t_image	image;
	t_window win;

	*map = NULL;
	//game = malloc(sizeof(t_game));
	win = new_window(300, 300, name);
	image = new_image(300, 300, win);

		draw_circle((t_circle){100, 120, 23, 0x0002f999}, image);
		draw_circle((t_circle){150, 250, 15, 0x00f022bf}, image);
		draw_rect((t_rect){10, 10, 20, 50, 0x005F5599}, image);
	  	draw_rect((t_rect){70, 200, 10, 50, 0x0012daf1}, image);
		mlx_put_image_to_window (image.win.mlx_ptr, image.win.win_ptr, image.img_ptr, 0, 0);

	mlx_loop(win.mlx_ptr);
	mlx_destroy_window(win.mlx_ptr, win.win_ptr);
	return ((void *)0);
}
