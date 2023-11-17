/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/17 12:31:44 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0m"
# define MAGENTA	"\e[0;35m"

# define ASSETSDIR 	"./assets/"
# define MAPSDIR 	"./maps/"

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_map
{
	int		collectibles;
	int		exits;
	int		players;
	int		width;
	int		height;
	char	**map;
	char	**map_validator;
	t_point	*player;
	t_point	*exit;
}			t_map;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	*map;
}				t_data;

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
t_map	*load_map(char *map_path, t_map *map);
t_map	*map_init(void);

//Errors and frees
void	errors(t_data *game, int code);
void	free_map(t_data *game);
#endif