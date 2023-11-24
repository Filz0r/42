/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:19:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 11:35:48 by fparreir         ###   ########.fr       */
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
		load_map(map_path, &result);
	if (result && *result == NULL)
		errors(result, 0);
	if (result && *result != NULL && check_for_invalid(result))
		errors(result, 2);
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
	}
	return (0);
}

// Opens the file where the map is inside and loads it into memory.
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

// reads the file line by line and places it inside a single string
char	*read_map(int fd)
{
	char		*line;
	char		*result;
	size_t		new_size;
	size_t		res_size;

	res_size = 0;
	result = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		new_size = res_size + ft_strlen(line) + 1;
		result = ft_realloc(result, new_size);
		ft_strlcat(result, line, new_size);
		res_size = new_size - 1;
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
