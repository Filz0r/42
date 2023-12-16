/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:25:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 16:31:38 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

static t_point	set_window_size(int width, int height)
{
	if (PRINT_MOVES == 0)
		return ((t_point){width * SIZE, (height * SIZE) + SIZE, -1, -1});
	else
		return ((t_point){width * SIZE, height * SIZE, -1, -1});
}

// TODO:docs
t_window	*new_window(int width, int height, char *name)
{
	t_window	*win;
	t_point		pt;

	win = malloc(sizeof(t_window));
	ft_memset(win, 0, sizeof(t_window));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (window_cleanup(win));
	pt = set_window_size(width, height);
	win->win_ptr = mlx_new_window
		(win->mlx_ptr, pt.x, pt.y, name);
	if (!win->win_ptr)
		return (window_cleanup(win));
	win->height = (height * SIZE) + SIZE;
	win->width = width * SIZE;
	return (win);
}
