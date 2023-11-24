/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:25:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 22:25:03 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

void	*map_cleanup(t_map *res)
{
	if (res)
	{
		if (res->player)
			free(res->player);
		if (res->start)
			free(res->start);
		if (res->exit)
			free(res->exit);
		if (res->collectibles)
			ft_lstiter(res->collectibles, free);
		free(res);
	}
	return (NULL);
}

void	*window_cleanup(t_window *w)
{
	if (w)
	{
		if (w->win_ptr)
			free(w->win_ptr);
		if (w->mlx_ptr)
			free(w->mlx_ptr);
		free(w);
	}
	return (NULL);
}

void	*images_cleanup(t_list *lst)
{
	//TODO: finish this
	return (NULL);
}

