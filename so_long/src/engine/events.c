/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:28:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/04 16:37:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

/**
 * @brief This function is what triggers the movement or an attempt of it
 * @param keysym the value of the key we pressed
 * @param game the t_game structure that contains everything.
 * @return always returns 1
 */
int	on_key(int keysym, t_game *game)
{
	if (keysym == XK_a || keysym == XK_Left)
		return (move_player(game, LEFT));
	else if (keysym == XK_s || keysym == XK_Down)
		return (move_player(game, DOWN));
	else if (keysym == XK_d || keysym == XK_Right)
		return (move_player(game, RIGHT));
	else if (keysym == XK_w || keysym == XK_Up)
		return (move_player(game, UP));
	if (keysym == XK_Escape)
		quit_game(game, EXIT_SUCCESS);
	return (1);
}

/**
 * @brief removes an collectible from the t_map structure that lives
 * inside of t_game structure
 * @param game the t_game struct we pass around
 * @param norm_point the point we just collided with and want to remove.
 */
void	remove_collectible(t_game *g, t_point norm_point)
{
	t_list	*curr;
	t_list	*prev;
	t_point	*temp;

	prev = NULL;
	curr = g->map->collectibles;
	while (curr)
	{
		temp = (t_point *)curr->content;
		if (temp && (temp->x / SIZE) == norm_point.x
			&& (temp->y / SIZE) == norm_point.y)
		{
			if (prev)
				prev->next = curr->next;
			else
				g->map->collectibles = curr->next;
			g->map->col_count--;
			ft_lstdelone(curr, free);
			g->map->map[norm_point.y][norm_point.x] = '0';
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

/**
 * @brief removes the flooded tiles from the queue stored inside t_game
 * and adds them to a linked list saved inside t_game
 * @param game the t_game struct
 * @return 1 if game->tiles_to_flood isn't NULL 0 if it is.
 */
int	will_raise_fire(t_game *g)
{
	t_point	to_clean;
	int		i;

	if (g->tiles_to_flood)
	{
		i = 0;
		while (i < g->kill_scale)
		{
			to_clean = remove_from_queue(g->tiles_to_flood);
			if (to_clean.x == -1 || to_clean.y == -1)
			{
				free_queue(g->tiles_to_flood);
				g->tiles_to_flood = NULL;
				break ;
			}
			ft_lstadd_back(&(g->flooded_tiles), ft_lstnew(new_point
					((t_point){to_clean.x * SIZE, to_clean.y * SIZE,
						to_clean.x * SIZE, to_clean.y * SIZE})));
			i++;
		}
		return (1);
	}
	return (0);
}
