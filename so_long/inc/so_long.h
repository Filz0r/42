/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:48:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/19 19:57:04 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0m"
# define MAGENTA	"\e[0;35m"


# define UP				1
# define DOWN			2
# define LEFT			3
# define RIGHT			4
# define CYCLE_SIZE		1000000
# define TILE_SIZE		32
# define FPS			60
# define FLOOR_PATH 	"assets/floor.xpm"
# define WALL_PATH		"assets/wall.xpm"
# define COLLECTIBLE	"assets/collectible.xpm"
# define PLAYER			"assets/player/"

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

typedef struct s_img{
	void	*floor;
	void	*walls;
	void	*collectible;
	t_list	*player;
}				t_img;

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
	t_map	*map;
	t_list 	*collectibles;
	int 	steps;
	int 	frames;
	int		redraw;
	int 	tile_size;
	double 	microseconds_time;
	unsigned long	*count;
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
char    *read_map(int fd, t_map *map);
t_map	*load_map(char *map_path, t_map *map);
t_map	*map_init(void);

//Errors and frees
void	errors(t_data *game, int code);
void	free_map(t_data *game);

//mlx stuff
int	on_destroy(t_data *game);
int	on_keypress(int keysym, t_data *game);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);
void	game_init(t_data *game);
void	draw_map(t_data *game);
void	put_walls(t_data *game);
int 	run_game(t_data *game);
int 	quit_game(t_data *game);
void	load_textures(t_data *game);
void	select_texture(t_data *game, int x, int y);
void	put_collectibles(t_data *game);
void get_collectibles(t_data *game);
void print_texture(t_data *game, void *img, int x, int y);
char *generate_player_path(int nb);
void	print_player(t_data *game, t_list *start, int x, int y);
void	load_player_textures(t_data *game);
void	ft_usleep(unsigned int microseconds);
void	recursive_workload(int count);
void	remove_collectible(t_data *g, int x, int y);

// movement
void	move_player(t_data *game, int action);
void	handle_movement(t_data *g, int x, int y, int action);
void	handle_movement_down(t_map *m, int x, int y);
void	handle_movement_left(t_map *m, int x, int y);
void	handle_movement_right(t_map *m, int x, int y);
#endif