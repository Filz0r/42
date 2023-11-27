/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:01:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 00:11:55 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

static int	put_pixel_valid(t_img img, int x, int y) {
	if (x >= 0 && y >= 0 && x < img.w && y < img.h) {
		return (*(unsigned int *)(img.addr + (y * img.line_len + x * (img.bpp / 8))) != 0xFF000000 &&
				*(unsigned int *)(img.addr + (y * img.line_len + x * (img.bpp / 8))) != 0x00000000);
	}
	return 0;
}

void	put_image_to_image(t_img *src, t_img *dest, int x, int y)
{
	int	i;
	int	k;

	i = 0;
	while (i < src->w)
	{
		k = 0;
		while (k < src->h)
		{
			if (put_pixel_valid(*src, i, k))
				put_pixel_img(*dest, x + i, y + k,
					get_pixel_img(*src, i, k));
			k++;
		}
		i++;
	}
}

void	draw_background(t_game *game)
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

static t_img	*create_overlay(t_window *w)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	res->win = w;
	res->img_ptr = mlx_new_image(w->mlx_ptr, w->width, w->height);
	if (!(res->img_ptr))
	{
		free(res);
		ft_putendl_fd("Error creating overlay", 2);
		return (NULL);
	}
	res->addr = mlx_get_data_addr
		(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	return (res);
}

void	draw_overlay(t_game *game)
{
	t_frame			*floor;
	t_img			*frame;
	int				x;
	int				y;

	floor = find_frame_by_entity(game->images, WALL);
	frame = (t_img *)((ft_lstget(floor->frames, 0))->content);
	game->overlay = create_overlay(game->win);
	y = -1;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == '1')
				put_image_to_image(frame, game->overlay, x * SIZE, y * SIZE);
		}
	}
	mlx_put_image_to_window(game->overlay->win->mlx_ptr,
		game->overlay->win->win_ptr, game->overlay->img_ptr, 0, 0);
}
