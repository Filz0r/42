/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:19:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 16:25:30 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// This function is responsible for checking if the map is able to be loaded
// into memory, if by any reason there is an error, game->map will be
// set to NULL, and the program will end without needing to handle with the
// game pointer.
char	**validate_map(char *map_path)
{
	char **result;

	result = NULL;
	if (check_file_path(map_path))
		errors(result, 1);
	else
		load_map(map_path, &result);
	//game->map = load_map(map_path, map_init());
	if (result && *result == NULL)
		errors(result, 0);
	if (result && *result != NULL && check_for_invalid(result))
		errors(result, 2);
//	get_info(game->map);
	if (result && *result != NULL && validate_details(result))
		errors(result, 3);
	if (result && *result != NULL && is_rectangle(result))
		errors(result, 4);
	if (result && *result != NULL && is_walled(result))
		errors(result, 5);
	if (result && *result != NULL && is_completable(result))
		errors(result, 6);
	return (result);
}

int	check_file_path(char *file)
{
	char	*check;
	size_t	size;

	check = ft_strnstr(file, ".ber", ft_strlen(file));
	if (check)
	{
		size = ft_strlen(check);
		if (size != 4)
			return (1);
	}
	return (0);
}
	/*
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
		errors(game, 6);*/



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
void	load_map(char *map_path, char ***temp)
{
	char		*result;
	int			file;

	if (*temp != NULL)
	{
		return ;
	}
	file = open(map_path, O_RDONLY);
	result = read_map(file);
	*temp = ft_split(result, '\n');
	free(result);
	close(file);
}

int	is_completable(char **map)
{
	char	**temp_map;
	int		player_x;
	int		player_y;

	if (*map == NULL)
		return (0);
	temp_map = ft_mapdup(map);
	find_player(temp_map, &player_x, &player_y);
	flood_fill(temp_map, player_x, player_y, 'F');
	if (!check_pathing(temp_map))
	{
		free_map(temp_map);
		return (0);
	}
	free_map(temp_map);
	return (1);
}

char **ft_mapdup(char **map)
{
	int		h;
	int		i;
	char	**res;

	i = 0;
	h = get_map_height(map);
	res = malloc(sizeof(char *) * (h + 1));
	while (map[i])
	{
		res[i] = ft_strdup(map[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// This function checks the pathing after the map_validator is flooded
// returns true if any E or C elements exist
int	check_pathing(char **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E' || map[y][x] == 'C')
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
