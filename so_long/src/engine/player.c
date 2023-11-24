/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:52:23 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 21:59:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"


t_player	*load_player(t_game *ptr)
{
	t_player	*res;

	res = malloc(sizeof(t_player));
	if (!res)
		return (NULL);
	res->start = *(ptr->map->start);
	res->current = ptr->map->player;
	res->walking = NULL;
	res->idle = NULL;
	res->dying = NULL;
	ft_lstadd_back(&(res->walking),
		ft_lstnew((void *)create_frame(ptr->win,
				WALK_PATH, PLAYER_WALKING, 4)));
	ft_lstadd_back(&(res->dying),
		ft_lstnew((void *)create_frame(ptr->win,
				IDLE_PATH, PLAYER_IDLE, 4)));
	ft_lstadd_back(&(res->idle),
		ft_lstnew((void *)create_frame(ptr->win,
				DIE_PATH, PLAYER_DYING, 4)));
	return (res);
}