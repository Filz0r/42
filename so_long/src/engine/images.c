/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:44:45 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/26 18:26:37 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"
#include "../../inc/engine.h"
#include <string.h>

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

t_frame	*create_frame(t_window *w,
	char *asset_path, t_entity type, int frame_num)
{
	t_frame	*res;

	res = malloc(sizeof(t_frame));
	if (!res)
		return (NULL);
	res->type = type;
	res->frames = NULL;
	load_frames(w, &(res->frames), asset_path, frame_num);
	res->total_frames = frame_num;
	res->current_frame = 0;
	res->delay = 0;
	res->last_updated = 0;
	return (res);
}

void	load_frames(t_window *w, t_list **lst, char *path, int size)
{
	int		i;
	char	*frame_path;
	char	*file_path;
	char	*temp;

	i = 0;
	if (size == 1)
		ft_lstadd_back(lst, ft_lstnew(create_image(path, w)));
	else
	{
		while (i < (size - 1))
		{
			temp = ft_itoa(i);
			frame_path = ft_strjoin(path, temp);
			file_path = ft_strjoin(frame_path, ".xpm");
			ft_lstadd_back(lst,
				ft_lstnew(create_image(file_path, w)));
			free(temp);
			free(frame_path);
			free(file_path);
			i++;
		}
	}
}

