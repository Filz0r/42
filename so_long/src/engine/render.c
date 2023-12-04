/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:01:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 20:20:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

// TODO: DOCUMENTATION
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
	render_fire(game);
	render_other_assets(game);
	render_animation(game, *(game->map->player), animation);
	fill_bottom(game);
	mlx_put_image_to_window(game->overlay->win->mlx_ptr,
		game->overlay->win->win_ptr, game->overlay->img_ptr, 0, 0);
	game->frames++;
}

void	select_asset_to_put(t_game *game, char c, t_point pos)
{
	t_img			*wall;
	t_img			*floor;

	wall = get_img_by_entity(game->images, WALL);
	floor = get_img_by_entity(game->images, FLOOR);
	put_image_to_overlay(floor, game, FLOOR, pos);
	if (c == '1')
		put_image_to_overlay(wall, game, WALL, pos);
}

void	render_fire(t_game *game)
{
	t_list	*coords;

	coords = game->flooded_tiles;
	while (coords)
	{
		render_animation(game, *((t_point *)(coords->content)), ENEMY);
		coords = coords->next;
	}
}

void	render_other_assets(t_game *game)
{
	t_img	*exit;
	t_img	*collectible;
	t_list	*coll_lst;

	collectible = get_img_by_entity(game->images, COLLECTIBLE);
	exit = get_img_by_entity(game->images, EXIT);
	if (game->map->collectibles == NULL)
		put_image_to_overlay(exit, game, EXIT, *(game->map->exit));
	else
	{
		coll_lst = game->map->collectibles;
		while (coll_lst)
		{
			put_image_to_overlay(collectible, game,
				COLLECTIBLE, *((t_point *)(coll_lst->content)));
			coll_lst = coll_lst->next;
		}
	}
}

void	render_animation(t_game *game, t_point pos, t_entity type)
{
	t_frame	*f;
	t_img	*i;

	f = find_frame_by_entity(game->images, type);
	if (f->current_frame == f->total_frames)
		f->current_frame = 0;
	i = (t_img *)(ft_lstget(f->frames, f->current_frame))->content;
	put_image_to_overlay(i, game, type, pos);
	f->current_frame++;
	f->current_frame %= f->total_frames;
}
