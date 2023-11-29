/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:25:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/29 15:43:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"

t_window	*new_window(int width, int height, char *name)
{
	t_window	*win;

	(void)name;
	win = malloc(sizeof(t_window));
	ft_memset(win, 0, sizeof(t_window));
	if (!win)
		return (NULL);
	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (window_cleanup(win));
	win->win_ptr = mlx_new_window
		(win->mlx_ptr, width * 32, height * 32, "so_long");
	if (!win->win_ptr)
		return (window_cleanup(win));
	win->height = height * SIZE;
	win->width = width * SIZE;
	return (win);
}
