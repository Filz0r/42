/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 22:05:13 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/18 22:56:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

//TODO: norm
void get_collectibles(t_data *game)
{
	int collectibles;
	t_list *result;
	int x, y, count = 0;
	t_point	*current;

	collectibles = game->map->collectibles;
	y = -1;
	result = NULL;
	while (game->map->map[++y])
	{
		x = -1;
		while (game->map->map[y][++x])
		{
			if (game->map->map[y][x] == 'C')
			{
				current = malloc(sizeof(t_point *));
				current->x = x;
				current->y = y;
				ft_lstadd_back(&result, ft_lstnew((void *)current));
				count++;
				if (count == collectibles)
					break;
			}
		}
	}
	game->collectibles = result;
}
