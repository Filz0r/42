/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 14:12:25 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "engine.h"


# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0m"
# define MAGENTA	"\e[0;35m"


//Map stuff
void	get_info(t_map *map);
t_map	*map_init(void);



char	**validate_map(char *map_path);
char	*read_map(int fd);
void	load_map(char *map_path, char ***map);
int		check_for_invalid(char **map);
int		validate_details(char **map);
void	handle_chars(char c, int *collectible, int *exits, int *players);
int		is_rectangle(char **map);
int		get_map_width(char **map);
int		get_map_height(char **map);
int		is_walled(char **map);
int		check_pathing(char **map);
char	**ft_mapdup(char **map);
void	find_player(char **map, int *x, int *y);
void	flood_fill(char **map, int x, int y, char fill_val);
int		invalid_char(char c);
int		is_completable(char **map);
int		check_file_path(char *file);






//Errors and frees
void	errors(char **map, int code);
void	free_map(char **map);


#endif