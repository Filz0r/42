/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:19:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/17 16:41:08 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function is responsible for checking if the map is able to be loaded
// into memory, if by any reason there is an error, game->map will be
// set to NULL, and the program will end without needing to handle with the
// game pointer.
void	validate_map(char *map_path, t_data *game)
{
	if (ft_strnstr(map_path, ".ber", ft_strlen(map_path)) == NULL)
		errors(game, 1);
	game->map = load_map(map_path, map_init());
	if (game->map == NULL)
		errors(game, 0);
	if (game->map != NULL && check_for_invalid(game->map))
		errors(game, 2);
	get_info(game->map);
	if (game->map != NULL && validate_details(game->map))
		errors(game, 3);
	if (game->map != NULL && is_rectangle(game->map))
		errors(game, 4);
	if (game->map != NULL && is_walled(game->map))
		errors(game, 5);
	if (game->map != NULL)
	{
		find_player(game->map);
		flood_fill(game->map, game->map->player->x, game->map->player->y, 'F');
	}
	if (game->map != NULL && check_pathing(game->map))
		errors(game, 6);
}

// Initializes the map pointer for the program, if memory allocation fails
// this function will return NULL
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
	result->map_validator = NULL;
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

// Opens the file where the map is inside and loads it into memory.
// And also sets its width and height;
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
			map->width = (int)ft_strlen(line) - 1;
		result = ft_strjoin(result, line);
		map->height++;
		free(line);
	}
	map->map = ft_split(result, '\n');
	map->map_validator = ft_split(result, '\n');
	free(result);
	close(file);
	return (map);
}

// This function checks the pathing after the map_validator is flooded
// returns true if any E or C elements exist
int	check_pathing(t_map *m)
{
	int	x;
	int	y;

	y = 0;
	while (m->map_validator[y])
	{
		x = 0;
		while (m->map_validator[y][x])
		{
			if (m->map_validator[y][x] == 'E' || m->map_validator[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

// This function counts the Exits, Collectibles and Players,
// it also sets the position of the exit in the map.
void	get_info(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	if (m == NULL)
		return ;
	while (m->map[++y])
	{
		x = -1;
		while (y < m->height && m->map[y][++x])
		{
			if (m->map[y][x] == 'C')
				m->collectibles++;
			else if (m->map[y][x] == 'E')
			{
				m->exits++;
				m->exit->x = x;
				m->exit->y = y;
			}
			else if (m->map[y][x] == 'P')
				m->players++;
		}
	}
}
