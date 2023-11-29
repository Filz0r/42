/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:25:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/29 20:47:15 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

//TODO: This file is GIGA bugged
void	*map_cleanup(t_map *res)
{
	if (res)
	{
		//free_game_map(&(res->map));
		if (res->player)
			free(res->player);
		if (res->start)
			free(res->start);
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
		if (w->win_ptr)
		{
			mlx_destroy_window(w->mlx_ptr, w->win_ptr);
			mlx_destroy_display(w->mlx_ptr);
		}
		if (w->mlx_ptr)
			free(w->mlx_ptr);
		free(w);
		w = NULL;
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

void	free_game_map(char ***map)
{
	char	**temp;
	int		i;

	i = 0;
	if (!map || !(*map))
		return ;
	temp = *map;
	while (temp[i] != 0)
		printf("%s\n", temp[i++]);
	i = 0;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
}