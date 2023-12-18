/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:25:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/04 16:38:08 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

/**
 * @brief cleans up the memory allocated to the t_map struct that lives inside
 * of t_game
 * @param map_ptr a pointer to a t_map struct
 * @return NULL
 */
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

/**
 * @brief destroys the mlx window and display and frees the mlx pointer and
 * window_ptr
 * @param window_ptr a pointer to the window we want to destroy
 * @return NULL
 */
void	*window_cleanup(t_window *w)
{
	if (w)
	{
		if (w->mlx_ptr)
		{
			if (w->win_ptr)
				mlx_destroy_window(w->mlx_ptr, w->win_ptr);
			mlx_destroy_display(w->mlx_ptr);
		}
		if (w->mlx_ptr)
			free(((*w).mlx_ptr));
		free(w);
	}
	return (NULL);
}

/**
 * @brief destroys the t_list of t_img pointers that a t_frame has
 * @param lst pointer to a list of t_frames
 * @return NULL
 */
void	*images_cleanup(t_list *lst)
{
	ft_lstclear(&lst, &destroy_frame);
	return (NULL);
}

/**
 * @brief calls mlx_destroy image on an valid t_img pointer and frees
 * the memory allocated on the pointer
 * @param image_ptr pointer to the t_img struct we want to free.
 */
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

/**
 * @brief frees a valid pointer of t_frame using libft utils and destroy_image
 * @param ptr an valid t_frame pointer
 */
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
