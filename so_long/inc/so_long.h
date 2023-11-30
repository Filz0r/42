/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 00:45:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0m"
# define MAGENTA	"\e[0;35m"


// Functions for loading the file and contents to memory
char	*read_map(int fd);
char	**validate_map(char *map_path);
char	**get_map(char *map_path);


// Utils
char	**mapdup(char **map);
void	flood_fill(char **map, int x, int y, char fill_val);
void	find_player(char **map, int *x, int *y);
int		check_file_path(char *file);
int		get_width(char **map);
int		get_height(char **map);

// Map Validation
int		check_for_invalid(char **map);
int		validate_details(char **map);
void	handle_chars(char c, int *collectible, int *exits, int *players);
int		is_rectangle(char **map);
int		is_walled(char **map);
int		check_pathing(char **map);
int		invalid_char(char c);
int		is_completable(char **map);

//Errors and frees
void	errors(char **map, int code);
void	free_map(char **map);


#endif