/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:44:45 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 19:27:57 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

/**
 * @brief creates a t_img object that contains an XPM file inside with valid
 * pixels that can be drawn in the screen
 * @param path path to the xpm file we want to open
 * @param win pointer to the t_window object that contains all the mlx stuff
 * @return either NULL if anything goes wrong or a valid pointer to an t_img
 * struct.
 */
t_img	*create_image(char *path, t_window *win)
{
	t_img	*res;

	res = (t_img *)malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	ft_memset(res, 0, sizeof(t_img));
	res->img_ptr = mlx_xpm_file_to_image
		(win->mlx_ptr, path, &(res->w), &(res->h));
	if (!(res->img_ptr))
	{
		ft_putendl_fd(path, 2);
		ft_putendl_fd("Error: file could not be read", 2);
		free(res);
		return (NULL);
	}
	res->addr = mlx_get_data_addr
		(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	res->win = win;
	return (res);
}

/**
 * @brief creates a mlx image with the size of the window, this is where
 * the game is drawn, every time a frame is put to a window, it means that
 * this image was filled with individual pixels for the entire window.
 * @param window pointer to the t_window struct that contains the mlx stuff
 * @return either NULL if the mlx_new_image function fails or malloc, or it
 * returns a pointer to a valid t_img struct that can be used as our canvas
 * that we draw into.
 */
t_img	*create_overlay(t_window *w)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	ft_memset(res, 0, sizeof(t_img));
	res->win = w;
	res->img_ptr = mlx_new_image(w->mlx_ptr, w->width, w->height);
	if (!(res->img_ptr))
	{
		free(res);
		ft_putendl_fd("Error creating overlay", 2);
		return (NULL);
	}
	res->w = w->width;
	res->h = w->height;
	res->addr = mlx_get_data_addr
		(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	return (res);
}

/**
 * @brief with some wierd math and type casting we can determine the color
 * of an pixel at the x and y positions, neat what you can find online.
 * @param img an t_img pointer that contains an image with pixels we want to
 * grab
 * @param x the x position of the pixel we want to grab
 * @param y the y position of the pixel we want to grab
 * @return returns an unsigned int that can be interpreted because it
 * basically gets casted to its hexadecimal value on the back-end which is what
 * determines the color of the pixel we are copying.
 */
unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)(
		(img->addr + (y * img->line_len) + (x * img->bpp / 8))));
}

/**
 * @brief puts the color of an pixel it receives as input in the x and y
 * position of the t_img struct pointer that it receives
 * @param img the t_img pointer we want to fill (usually the overlay of the
 * t_game structure)
 * @param x the x position of the pixel we want to fill.
 * @param y the y position of the pixel we want to fill.
 * @param color the color of the pixel it gets as output of get_pixel_img
 *
 * This function uses a formula equal to get_pixel image to determine
 * the position of the pixel we want to fill and then sets it with
 * the value it gets from get_pixel_img, the types are casted inside because
 * we basically only get hexadecimal values that fit inside an int.
 * This function does not put transparent pixels on the destination, because
 * those are bugged in Linux.
 */
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

/**
 * @brief This function is what actually determines the position of the pixels
 * we want to fill and places them inside the t_img overlay that is pushed
 * to the window.
 * @param src the image we want to put inside the overlay
 * @param g the t_game structure that contains the overlay
 * @param type the type of image we are drawing in the screen
 * @param pos the position of the overlay we want to start filling our pixels at
 */
void	put_image_to_overlay(t_img *src, t_game *g, t_entity type, t_point pos)
{
	int	i;
	int	k;
	int	x;
	int	y;

	i = 0;
	x = pos.x;
	y = pos.y;
	while (i < src->h)
	{
		k = 0;
		while (k < src->w)
		{
			if ((type == PLAYER_WALKING || type == PLAYER_IDLE) && g->mirror)
				put_pixel_img(g->overlay, x + src->h - k - 1, y + i,
					get_pixel_img(src, k, i));
			else
				put_pixel_img(g->overlay, x + k, y + i,
					get_pixel_img(src, k, i));
			k++;
		}
		i++;
	}
}
