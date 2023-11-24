/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:45:42 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 21:59:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"


t_map	*load_map(char **map)
{
	t_map	*res;

	res = malloc(sizeof(t_map));
	if (!res)
		return (NULL);
	res->map = map;
	res->collectibles = NULL;
	res->height = get_map_height(map);
	res->width = get_map_width(map);
	res->start = get_point(map, 'P');
	if (!(res->start))
		return (map_cleanup(res));
	res->player = get_point(map, 'P');
	res->exit = get_point(map, 'E');
	if (!(res->exit))
		return (map_cleanup(res));
	get_collectibles(map, &(res->collectibles));
	if (res->collectibles == NULL)
		return (map_cleanup(res));
	res->col_count = ft_lstsize(res->collectibles);
	return (res);
}

void	load_assets(t_window *win, t_list **lst)
{
	ft_lstadd_back(lst,
		ft_lstnew((void *)create_frame(win, FLOOR_PATH, FLOOR, 1)));
	ft_lstadd_back(lst,
		ft_lstnew((void *)create_frame(win, EXIT_PATH, EXIT, 1)));
	ft_lstadd_back(lst,
		ft_lstnew((void *)create_frame(win, COLL_PATH, COLLECTIBLE, 1)));
	ft_lstadd_back(lst,
		ft_lstnew((void *)create_frame(win, WALL_PATH, WALL, 1)));
}
