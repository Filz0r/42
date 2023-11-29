/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:28:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/29 12:39:59 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

int	on_keypress(int keysym, t_game *game)
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
		quit_game(game);
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
			g->map->collectibles--;
//			free(temp);
//			free(curr);
			ft_lstdelone(curr, free);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}
