/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:36:27 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/15 19:04:21 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../inc/so_long.h"

void	check_map(char *map_path, t_data *game)
{
	game->map = load_map(map_path, map_init());
	if (game->map == NULL)
		errors(game, 0);
	// validate map bellow
}

t_map	*map_init(void)
{
	t_map	*result;

	result = malloc(sizeof(t_map));
	if (!result)
		return (NULL);
	result->player = malloc(sizeof(t_point));
	if (!result->player)
		return (NULL);
	result->exit = malloc(sizeof(t_point));
	if (!result->exit)
		return (NULL);
	result->map = NULL;
	result->collectibles = 0;
	result->exits = 0;
	result->players = 0;
	result->height = 0;
	result->width = 0;
	result->player->x = 0;
	result->player->y = 0;
	result->exit->x = 0;
	result->exit->y = 0;
	return (result);
}

t_map	*load_map(char *map_path, t_map *map)
{
	int		file;
	char	*line;
	char	*result;

	file = open(map_path, O_RDONLY);
	result = ft_strdup("");
	if (map == NULL)
		return (NULL);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		if (map->width == 0)
		{
			map->width = (int)ft_strlen(line);
		}
		result = ft_strjoin(result, line);
		map->height++;
		free(line);
	}
	map->map = ft_split(result, '\n');
	free(result);
	close(file);
	return (map);
}
