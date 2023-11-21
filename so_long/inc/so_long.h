/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/20 19:39:48 by fparreir         ###   ########.fr       */
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
int		check_pathing(t_map *map);
int		check_for_invalid(t_map *map);
int		invalid_char(char c);
int		validate_details(t_map *m);
int		is_rectangle(t_map *m);
int		is_walled(t_map *m);
void	validate_map(char *map_path, t_data *game);
void	flood_fill(t_map *m, int x, int y, char fill_val);
void	get_info(t_map *map);
void	find_player(t_map *m);
char    *read_map(int fd, t_map *map);
t_map	*load_map(char *map_path, t_map *map);
t_map	*map_init(void);

//Errors and frees
void	errors(t_data *game, int code);
void	free_map(t_data *game);


#endif