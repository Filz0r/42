/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:38:14 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/27 16:14:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../inc/engine_utils.h"

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

// Finds the color of the current pixel we are trying to draw
unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)(
		(img->addr + (y * img->line_len) + (x * img->bpp / 8))));
}

// puts the pixel inside the image object
void	put_pixel_img(t_img *img, int x, int y, int color)
{
	char	*dest;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x <= img->w && y <= img->h)
	{
		dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
		*(unsigned int *)dest = (unsigned int)color;
	}
}
