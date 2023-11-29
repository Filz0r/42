/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:25:03 by fparreir          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2023/11/29 19:07:38 by fparreir         ###   ########.fr       */
=======
/*   Updated: 2023/11/29 17:37:34 by fparreir         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

void	*map_cleanup(t_map *res)
{
	if (res)
	{
//		if (res->player)
//			free(res->player);
//		if (res->start)
//			free(res->start);
//		if (res->exit)
//			free(res->exit);
		if (res->collectibles)
			ft_lstclear(&(res->collectibles), free);
<<<<<<< Updated upstream
		free_game_map(res->map);
		free(res);
=======
//		free(res);
>>>>>>> Stashed changes
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
	}
	return (NULL);
}

void	*images_cleanup(t_list *lst)
{
	t_list	*next;
	t_frame	*temp;

	while (lst)
	{
		temp = (t_frame *)lst->content;
		if (temp != NULL)
			destroy_frame(temp);
		next = lst->next;
		ft_lstdelone(lst, destroy_frame);
		lst = next;
	}
	return (NULL);
}

void	destroy_image(t_img *ptr)
{

<<<<<<< Updated upstream
	img = (t_img *)ptr;
	if (img != NULL)
=======
	if (ptr)
>>>>>>> Stashed changes
	{
		if (ptr->img_ptr)
			mlx_destroy_image(ptr->win->mlx_ptr, ptr->img_ptr);
		free(ptr);
	}
}

void	destroy_frame(void *ptr)
{
	t_list	*temp;
	t_list	*next;
	t_frame	*frame;

	frame = (t_frame *)ptr;
	if (frame != NULL)
	{
<<<<<<< Updated upstream
		ft_lstclear(&(frame->frames), destroy_image);
		free(frame);
=======
		temp = frame->frames;
		while (temp)
		{
			if (temp->next)
				next = temp->next;
			else
				next = NULL;
			destroy_image((t_img *)temp->content);
			free(temp);
			temp = next;
		}
		free(ptr);
>>>>>>> Stashed changes
	}
}

void	free_game_map(char **map)
{
	char	**temp;
	int		i;

	i = 0;
	if (!map || !(*map))
		return ;
	temp = map;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
//	*map = NULL;
}