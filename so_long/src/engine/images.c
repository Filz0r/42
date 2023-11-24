/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:44:45 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 16:48:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine.h"

t_img	*create_image(char *path, t_window *win)
{
	t_img	*res;

	res = malloc(sizeof(t_img));
	if (!res)
		return (NULL);
	res->img_ptr = mlx_xpm_file_to_image
		(win->mlx_ptr, path, &(res->w), &(res->h));
	if (!(res->img_ptr))
		ft_putendl_fd("Error: file could not be read", 2);
	else
		res->addr = mlx_get_data_addr
			(res->img_ptr, &(res->bpp), &(res->line_len), &(res->endian));
	return (res);
}

t_frame	*create_frame(t_window *w,
	char *asset_path, t_entity type, int frame_num)
{
	t_frame	*res;

	res = malloc(sizeof(t_frame));
	if (!res)
		return (NULL);
	res->type = type;
	res->frames = load_frames(w, asset_path, frame_num);
	res->total_frames = frame_num;
	res->current_frame = 0;
	res->delay = 0;
	res->last_updated = 0;
	return (res);
}

t_list	*load_frames(t_window *w, char *path, int size)
{
	t_list	*frames;
	int		i;
	char	*frame_path;
	char	*file_path;

	frames = NULL;
	i = 0;
	if (size == 1)
		ft_lstadd_back(&frames, (void *)create_image(path, w));
	else
	{
		while (i < (size - 1))
		{
			frame_path = ft_strjoin(path, ft_itoa(i));
			file_path = ft_strjoin(frame_path, ".xpm");
			ft_lstadd_back(&frames, (void *)create_image(file_path, w));
			free(frame_path);
			free(file_path);
			i++;
		}
	}
	return (frames);
}

// Finds the color of the current pixel we are trying to draw
unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)(
		(img.addr + (y * img.line_len) + (x * img.bpp / 8))));
}

// puts the pixel inside the image object
void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dest;

	if (color == (int)0x00000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dest = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dest = color;
	}
}
