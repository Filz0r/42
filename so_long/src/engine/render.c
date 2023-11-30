/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 17:01:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 19:55:56 by fparreir         ###   ########.fr       */
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
	render_other_assets(game);
	handle_player_render(game, animation);
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

void	handle_player_render(t_game *game, t_entity animation)
{
	t_frame	*p_frame;
	t_img	*p_img;

	p_frame = find_frame_by_entity(game->images, animation);
	if (p_frame->current_frame == p_frame->total_frames - 1)
		p_frame->current_frame = 0;
	p_img = (t_img *)(ft_lstget(p_frame->frames,
				p_frame->current_frame))->content;
	if (game->mirror)
		put_image_to_overlay(p_img, game,
			PLAYER_WALKING, *(game->map->player));
	else
		put_image_to_overlay(p_img, game,
			PLAYER_WALKING, *(game->map->player));
	p_frame->current_frame++;
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

void	fill_bottom(t_game *g)
{
	int		i;
	t_img	*floor;

	i = 0;
	floor = get_img_by_entity(g->images, FLOOR);
	while (i < g->map->width)
	{
		put_image_to_overlay(floor, g, FLOOR, (t_point){i * SIZE,
			g->map->height * SIZE, i, i});
		i++;
	}
	draw_game_ticks(g);
	draw_game_moves(g);
}

void	draw_game_ticks(t_game *g)
{
	t_frame	*digits;
	t_img	*digit;
	char	*temp;
	int		i;

	i = 0;
	digits = find_frame_by_entity(g->images, DIGITS);
	temp = ft_itoa((int)g->tick);
	while (temp[i])
	{
		digit = (t_img *)(ft_lstget(digits->frames,
					temp[i] - '0'))->content;
		put_image_to_overlay(digit, g, DIGITS,
			(t_point){i * SIZE, g->map->height * SIZE, i, i});
		i++;
	}
	free(temp);
}

void			draw_game_moves(t_game *g)
{
	t_frame	*digits;
	t_img	*digit;
	char	*temp;
	int		i;
	int 	k;

	temp = ft_itoa((int)g->moves);
	i = ft_strlen(temp) - 1;
	k = 0;
	digits = find_frame_by_entity(g->images, DIGITS);
	while (i >= 0)
	{
		digit = (t_img *)(ft_lstget(digits->frames,
					temp[k++] - '0'))->content;
		put_image_to_overlay(digit, g, DIGITS,
			(t_point){((g->map->width * SIZE) - (i * SIZE)) - SIZE, g->map->height * SIZE, i, i});
		i--;
	}
	free(temp);
}