/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:05:34 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 19:48:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

t_frame	*create_frame(t_window *w,
	char *asset_path, t_entity type, int frame_num)
{
	t_frame	*res;

	res = malloc(sizeof(t_frame));
	if (!res)
		return (NULL);
	ft_memset(res, 0, sizeof(t_frame));
	res->type = type;
	res->frames = NULL;
	load_frames(w, &(res->frames), asset_path, frame_num);
	res->total_frames = frame_num;
	res->current_frame = 0;
	return (res);
}

void	load_frames(t_window *w, t_list **lst, char *path, int size)
{
	int		i;
	char	*frame_path;
	char	*file_path;
	char	*temp;

	if (size == 1)
		ft_lstadd_back(lst, ft_lstnew(create_image(path, w)));
	else
	{
		i = 0;
		while (i <= (size - 1))
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
