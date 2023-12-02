/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:25:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 22:21:57 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

//TODO: DOCUMENTATION
void	*map_cleanup(t_map *res)
{
	if (res)
	{
		if (res->player)
			free(res->player);
		if (res->exit)
			free(res->exit);
		if (res->collectibles)
			ft_lstclear(&(res->collectibles), free);
		free(res);
	}
	return (NULL);
}

void	*window_cleanup(t_window *w)
{
	if (w)
	{
		if (w->mlx_ptr)
		{
			if (w->win_ptr)
				mlx_destroy_window(w->mlx_ptr, w->win_ptr);
		}
		if (w->mlx_ptr)
			free(((*w).mlx_ptr));
		free(w);
	}
	return (NULL);
}

void	*images_cleanup(t_list *lst)
{

	ft_lstclear(&lst, &destroy_frame);
	return (NULL);
}

void	destroy_image(void *ptr)
{
	t_img	*img;

	img = (t_img *)ptr;
	if (img != NULL)
	{
		mlx_destroy_image(img->win->mlx_ptr, img->img_ptr);
		free(img);
	}
}

void	destroy_frame(void *ptr)
{
	t_frame	*frame;

	frame = (t_frame *)ptr;
	if (frame != NULL)
	{
		ft_lstclear(&(frame->frames), destroy_image);
		free(frame);
	}
}
