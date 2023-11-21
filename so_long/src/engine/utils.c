/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:36:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 17:39:12 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/engine.h"

t_window	new_window(int w, int h, char *name)
{
	void		*mlx;
	t_window	result;

	mlx = mlx_init();
	result.mlx_ptr = mlx;
	result.win_ptr = mlx_new_window(mlx, w, h, name);
	result.width = w;
	result.height = h;
	return (result);
}

t_image	new_image(int w, int h, t_window win)
{
	t_image	image;

	image.win = win;
	image.img_ptr = mlx_new_image(win.mlx_ptr, w, h);
	image.addr = mlx_get_data_addr
		(image.img_ptr, &(image.bpp), &(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

void	put_pixel_img(t_image img, int x, int y, int color)
{
	char	*dest;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dest = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dest = color;
	}
}

void	draw_rect(t_rect rect, t_image img)
{
	unsigned short int	i;
	unsigned short int	k;

	i = 0;
	while (i < rect.size_h && i + rect.y < img.h)
	{
		k = 0;
		while (k < rect.size_w && k < img.w)
		{
			put_pixel_img(img, k + rect.x, i + rect.y, rect.color);
			k++;
		}
		i++;
	}
}

void	draw_circle(t_circle circle, t_image img) {
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < circle.radius * 2 && i + circle.y < img.h)
	{
		j = 0;
		while (j < circle.radius * 2 && j + circle.x < img.w)
		{
			if (((j - circle.radius) * (j - circle.radius)) + ((i - circle.radius) * (i - circle.radius)) < (circle.radius * circle.radius))
			{
				put_pixel_img(img, j + circle.x, i + circle.y, circle.color);
			}
			j++;
		}
		i++;
	}
}