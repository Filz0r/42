/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:38:14 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 18:49:46 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

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

t_point	normalize_point(t_point point,
	double threshold_x, double threshold_y)
{
	return ((t_point){
		normalize(point.relative_x, threshold_x),
		normalize(point.relative_y, threshold_y),
		point.relative_x,
		point.relative_y
	});
}

t_point	interpolate_point(t_point current, t_point target, double factor)
{
	return ((t_point){current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y),
		current.x + factor * (target.x - current.x),
		current.y + factor * (target.y - current.y)});
}

t_point		scale_up(t_point pt)
{
	return ((t_point){pt.x * SIZE, pt.y * SIZE, pt.x * SIZE, pt.y * SIZE});
}

t_point		update_start(char **map, char to_find)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == to_find)
				return ((t_point){x, y, x, y});
		}
	}
	return ((t_point){-1, -1, -1, -1});
}
