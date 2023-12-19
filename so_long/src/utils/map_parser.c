/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 21:19:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/19 13:20:43 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

/**
 * @brief from the path we get from the program argument we try to load it into
 * a valid map that we can then pass into the game
 * @param map_path path to the file we want to open
 * @return either returns a valid char** map to the main function, or exits the
 * program because an error was found
 *
 * This function is responsible for checking if the map is able to be loaded
 * into memory, if by any reason there is an error, game->map will be
 * set to NULL, and the program will end without needing to handle with the
 * game pointer.
 */
char	**validate_map(char *map_path)
{
	char	**result;

	result = NULL;
	if (check_file_path(map_path))
		errors(result, 1);
	else
		result = get_map(map_path);
	if (result == NULL || *result == NULL)
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

/**
 * @brief validates that the path we are getting from the arguments ends in .ber
 * @param file filepath we want to check
 * @return 1 if true 0 if the file path doesn't end in .ber
 *
 * Checks if the argument has .ber inside
 * then gets the length of the string from the pointer it gets
 * if its not equal to 4 return false, aka you just tried to
 * break my parser and failed.
 */
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

/**
 * @brief Opens a file descriptor with the valid path, then loads its contents
 * into a 2D char array. If the file has empty lines anywhere except at the end
 * of the file read_map will fail and will make the map not valid anymore
 * @param map_path a path to a file ending in .ber
 * @return either returns a valid char ** that we can proceed to validate or
 * null if read_map fails or finds empty lines.
 */
char	**get_map(char *map_path)
{
	char		**ret;
	char		*line;
	int			file;
	int			sz;

	sz = 0;
	file = open(map_path, O_RDONLY);
	if (file == -1)
		return (NULL);
	while (1)
	{
		line = get_next_line(file);
		if (!line)
			break ;
		free(line);
		sz++;
	}
	close(file);
	file = open(map_path, O_RDONLY);
	ret = read_map(file, sz + 1);
	close(file);
	if (!ret)
		return (ft_fsplit(ret), NULL);
	return (trim_map(ret, sz + 1));
}

/**
 * @brief this function reads the map line by line and places it inside a single
 * string, if get_next_line is given an invalid fd it will return NULL so this
 * function will also return NULL, same behavior happens for lines that only
 * have a '\\n', meaning that if the file isn't a perfect square/rectangle
 * this function will also return NULL
 * @param fd
 * @return Either returns a NULL terminated string or NULL, check brief for
 * explanation on causes to NULL.
 */
char	**read_map(int fd, int size)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * size);
	if (!map)
		return (NULL);
	map[0] = get_next_line(fd);
	if (!map[0])
		return (free(map), NULL);
	while (++i < size)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break ;
	}
	return (map);
}

/**
 * @brief creates a temporary map that is flood filled from the position
 * of 'P' an replaces everything that isn't a wall, if after running this
 * the map still has chars other than 'F' and '1' it means the map is
 * not completable.
 * @param map the char ** we want to check
 * @return either 1 if the map is completable or 0 if it isn't
 */
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
		return (free_map(temp_map), 0);
	free_map(temp_map);
	return (1);
}
