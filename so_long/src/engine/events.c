/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:28:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 20:17:42 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

//TODO: DOCUMENTATION
int	on_key(int keysym, t_game *game)
{
	printf("pressed: %d\n", keysym);
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
					((t_point){to_clean.x * SIZE, to_clean.y * SIZE, 0, 0})));
			i++;
		}
		return (1);
	}
	return (0);
}

