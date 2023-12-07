/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:19:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/05 10:43:42 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// This function is responsible for checking if the map is able to be loaded
// into memory, if by any reason there is an error, game->map will be
// set to NULL, and the program will end without needing to handle with the
// game pointer.
char	**validate_map(char *map_path)
{
	char	**result;

	result = NULL;
	if (check_file_path(map_path))
		errors(result, 1);
	else
		result = get_map(map_path);
	if (result == NULL)
		errors(result, 0);
	if (result && *result != NULL && check_for_invalid(result))
		errors(result, 2);
	if (result && *result != NULL && validate_details(result) == 1)
		errors(result, 3);
	if (result && *result != NULL && is_rectangle(result))
		errors(result, 4);
	if (result && *result != NULL && is_walled(result))
		errors(result, 5);
	if (result && *result != NULL && is_completable(result))
		errors(result, 6);
	return (result);
}

// checks if the argument has .ber inside
// then gets the length of the string from the pointer it gets
// if its not equal to 4 return false, aka you just tried to
// break my parser and failed.
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
		return (0);
	}
	return (1);
}

// Opens the file where the map is inside and loads it into memory.
char	**get_map(char *map_path)
{
	char		**ret;
	char		*result;
	int			file;

	file = open(map_path, O_RDONLY);
	result = read_map(file);
	if (!result)
		return (NULL);
	ret = ft_split(result, '\n');
	free(result);
	close(file);
	return (ret);
}

// reads the file line by line and places it inside a single string
char	*read_map(int fd)
{
	char	*line;
	char	*result;
	char	*temp;

	result = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (ft_strlen(result) == 0)
			{
				free(result);
				return (NULL);
			}
			break ;
		}
		if (ft_strlen(line) == 1)
			return (free(result), free(line), NULL);
		temp = ft_strjoin(result, line);
		free(result);
		result = temp;
		free(line);
	}
	return (result);
}

// creates a new temporary map and runs flood fill inside this map
// then checks if there are still valid characters inside the map
// frees the temporary map and returns the answer
int	is_completable(char **map)
{
	char	**temp_map;
	int		player_x;
	int		player_y;

	if (*map == NULL)
		return (0);
	temp_map = mapdup(map);
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
