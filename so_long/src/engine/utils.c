/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:38:14 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 11:58:23 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

//TODO: docs
int	normalize(double nb, double threshold)
{
	int	res;

	res = (int)nb;
	if (nb > res + threshold)
		return (res + 1);
	else
		return (res);
}

// gets an t_frame pointer from a list using the entity value
t_frame	*find_frame_by_entity(t_list *lst, t_entity entity)
{
	t_list	*current;
	t_frame	*frame;

	current = lst;
	while (current)
	{
		frame = (t_frame *)current->content;
		if (frame && frame->type == entity)
			return (frame);
		current = current->next;
	}
	return (NULL);
}

t_img	*get_img_by_entity(t_list *lst, t_entity entity)
{
	t_frame	*frame;
	t_img	*img;

	frame = find_frame_by_entity(lst, entity);
	img = (t_img *)((ft_lstget(frame->frames, 0))->content);
	if (!img)
		return (NULL);
	return (img);
}

int	count_fillable_tiles(char **map)
{
	int	x;
	int	y;
	int	count;

	count = 0;
	y = -1;
	while (map[++y] != 0)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '1')
				continue ;
			else
				count++;
		}
	}
	return (count);
}

char	**map_clone(t_map *map)
{
	int		k;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!res)
		return (NULL);
	k = -1;
	while (map->map[++k])
		res[k] = ft_strdup(map->map[k]);
	res[k] = 0;
	return (res);
}
