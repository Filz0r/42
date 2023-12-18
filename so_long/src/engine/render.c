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

/**
 * @brief this function is responsible for filling our overlay mlx image with
 * all the correct pixels, for our entire map pointer, basically this function
 * constantly fills the canvas with pixels, the pre processor macros defined
 * in engine.h will be used to determine if an asset is rendered or not,
 * this basically means that the function always tries to render all assets.
 * @param game that sneaky t_game structure we pass everywhere
 * @param animation the type of animation we want to render, this is only used
 * for the player animations.
 */
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

/**
 * @brief This is an auxiliary function for render_frame, it basically always
 * fills the given t_point with the floor pixels, and then if the passed char
 * is an '1' it then draws the wall on top of the floor pixels, this is
 * done so that our floor and walls are always rendered onto the screen.
 * @param game that darn t_game pointer
 * @param c the char we want to check if its a wall or nor
 * @param pos the position of the screen that we want to fill.
 */
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

/**
 * @brief if the pre processor macros allow for it, it will go trough the
 * linked list of fire positions stored in t_game and render them in their
 * corresponding positions.
 * @param game that darn t_game struct again.
 */
void	render_fire(t_game *game)
{
	t_list	*coords;

	if (KILL_PLAYER != 1)
		return ;
	coords = game->flooded_tiles;
	while (coords)
	{
		render_animation(game, *((t_point *)(coords->content)), ENEMY);
		coords = coords->next;
	}
}

/**
 * @brief renders the collectibles and the exit if the logic allows for it
 * @param game once again t_game
 */
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

/**
 * @brief an auxiliary function used to render animation slices on the canvas
 * its abstracted in order to work with any kind of animated asset.
 * @param game that darn t_game pointer
 * @param pos the position where we want to render our asset at.
 * @param type the type of object we are tying to render.
 *
 * NOTE: traditionally speaking the formula at the end of this functions limits
 * the numbers in a fashion that they start from 1, 2, 3 ... nmax and when
 * current_frame is equal to the total of frames it resets current_frame to 1,
 * but render frames from 0 to nmax meaning that we need to manually reset
 * this variable to 0 when we get to nmax.
 */
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
