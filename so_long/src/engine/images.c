/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:44:45 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/28 12:12:22 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"
#include <string.h>

//TODO: Norm + documentation
t_img	*create_image(char *path, t_window *win)
{
	t_img	*res;

	res = (t_img *)malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	res->img_ptr = mlx_xpm_file_to_image
		(win->mlx_ptr, path, &(res->w), &(res->h));
	if (!(res->img_ptr))
	{
		ft_putendl_fd(path, 2);
		ft_putendl_fd("Error: file could not be read", 2);
		free(res);
		return (NULL);
	}
	if (strcmp(path, FLOOR_PATH) == 0 || strcmp(path, WALL_PATH) == 0)
	{
		ft_printf("%s ptr:%p\n" ,path, res);
	}
	res->addr = mlx_get_data_addr
		(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	res->win = win;
	return (res);
}

t_img	*create_overlay(t_window *w)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (!res)
		return (NULL);
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

void	put_image_to_image(t_img *src, t_img *dest, int x, int y)
{
	int	i;
	int	k;

	i = 0;
	while (i < src->h)
	{
		k = 0;
		while (k < src->w)
		{
			put_pixel_img(dest, x + k, y + i,
				get_pixel_img(src, k, i));
			k++;
		}
		i++;
	}
}