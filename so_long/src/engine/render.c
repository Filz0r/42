/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:01:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 22:33:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

void	put_image_to_image(t_img *src, t_img *dest, int x, int y)
{
	int	i;
	int	k;

	i = 0;
	while (i < src->h)
	{
		k = 0;
		while (k < src->w)
		{
			put_pixel_img(dest, x + k, y + i,
				get_pixel_img(src, k, i));
			k++;
		}
		i++;
	}
}

t_img	*create_overlay(t_window *w)
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
	res->w = w->width;
	res->h = w->height;
	res->addr = mlx_get_data_addr
		(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	return (res);
}

void	render_frame(t_game *game, t_entity animation)
{
	int		x;
	int		y;
	t_point	pos;

	y = 0;
	while (game->map->map[y])
	{
		x = 0;
		while (game->map->map[y][x])
		{
			pos = (t_point){x * SIZE, y * SIZE};
			select_asset_to_put(game, game->map->map[y][x], pos);
			x++;
		}
		y++;
	}
	handle_player_render(game, animation);
	mlx_put_image_to_window(game->overlay->win->mlx_ptr,
		game->overlay->win->win_ptr, game->overlay->img_ptr, 0, 0);
}

void	select_asset_to_put(t_game *game, char c, t_point pos)
{
	t_img			*wall;
	t_img			*floor;
	t_img			*collectible;
	t_img			*exit;


	wall = get_img_by_entity(game->images, WALL);
	floor = get_img_by_entity(game->images, FLOOR);
	collectible = get_img_by_entity(game->images, COLLECTIBLE);
	exit = get_img_by_entity(game->images, EXIT);
	put_image_to_image(floor, game->overlay, pos.x, pos.y);
	if (c == '1')
		put_image_to_image(wall, game->overlay, pos.x, pos.y);
	else if (c == 'C')
		put_image_to_image(collectible, game->overlay, pos.x, pos.y);
	else if (c == 'E')
		put_image_to_image(exit, game->overlay, pos.x, pos.y);
//	else if (c == 'P')
//		handle_player_render(game, animation);
}

void	handle_player_render(t_game *game, t_entity animation)
{
	t_frame	*p_frame;
	t_img	*p_img;

	p_frame = find_frame_by_entity(game->images, animation);
	if (p_frame->current_frame == p_frame->total_frames - 1)
		p_frame->current_frame = 0;
	p_img = (t_img *)(ft_lstget(p_frame->frames,
				p_frame->current_frame))->content;
	put_image_to_image(p_img, game->overlay,
		game->map->player->x, game->map->player->y);
	p_frame->current_frame++;
}
