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
			pos = (t_point){x * SIZE, y * SIZE, (double)x, (double)y};
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
