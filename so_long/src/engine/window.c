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

/**
 * @brief Defines a t_point that is used to determine the size of the window
 * mlx is going to open
 * @param width an 1:1 scale map width
 * @param height an 1:1 scale map height
 * @return an t_point with the size we want to use
 *
 * NOTE: This makes use of pre processor macros to check what is supposed to
 * happen, by default te window doesn't have the height required to draw the
 * counters on the window, but with the use of some macros on compilation time
 * we can change this behaviour.
 */
static t_point	set_window_size(int width, int height)
{
	if (PRINT_MOVES == 0)
		return ((t_point){width * SIZE, (height * SIZE) + SIZE, -1, -1});
	else
		return ((t_point){width * SIZE, height * SIZE, -1, -1});
}

/**
 * @brief Creates and opens an mlx window where our game will be drawn into.
 * @param width the 1:1 width of the map
 * @param height the 1:1 height of the map
 * @param name the name of the window we want to create.
 * @return returns NULL if malloc fails or if mlx_init fails, otherwise it
 * returns a valid pointer to a t_window structure.
 */
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
