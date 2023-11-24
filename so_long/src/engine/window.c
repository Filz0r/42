/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:25:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 20:17:07 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"

t_window	*new_window(int width, int height, char *name)
{
	t_window	*win;

	win = malloc(sizeof(t_window));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (window_cleanup(win));
	win->win_ptr = mlx_new_window
		(win->mlx_ptr, width * SIZE, height * SIZE, name);
	win->height = height * SIZE;
	win->width = width * SIZE;
	return (win);
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
