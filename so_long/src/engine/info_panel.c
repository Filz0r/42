/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_panel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 21:49:54 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/04 16:37:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

// TODO DOCS
void	fill_bottom(t_game *g)
{
	int		i;
	t_img	*floor;

	if (PRINT_MOVES == 1)
		return ;
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

void	draw_game_moves(t_game *g)
{
	t_frame	*digits;
	t_img	*digit;
	char	*temp;
	int		i;
	int		k;

	temp = ft_itoa((int)g->moves);
	i = ft_strlen(temp) - 1;
	k = 0;
	digits = find_frame_by_entity(g->images, DIGITS);
	while (i >= 0)
	{
		digit = (t_img *)(ft_lstget(digits->frames, temp[k++] - '0'))->content;
		put_image_to_overlay(digit, g, DIGITS,
			(t_point){((g->map->width * SIZE) - (i * SIZE)) - SIZE,
			g->map->height * SIZE, i, i});
		i--;
	}
	free(temp);
}
