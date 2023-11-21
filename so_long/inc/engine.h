//
// Created by filipe on 20/11/23.
//

#ifndef SO_LONG_ENGINE_H
#define SO_LONG_ENGINE_H

#include "../libft/includes/libft.h"
#include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define UP				1
# define DOWN			2
# define LEFT			3
# define RIGHT			4
# define CYCLE_SIZE		1000000
# define TILE_SIZE		32
# define FPS			60
# define TICK_CYCLE		500000000
# define FLOOR_PATH 	"assets/floor.xpm"
# define WALL_PATH		"assets/wall.xpm"
# define COLLECTIBLE	"assets/collectible.xpm"
# define PLAYER			"assets/player/"
# define EXIT			"assets/exit.xpm"

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
	void	*exit;
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
	long 	microseconds_time;
	unsigned long	ticks;
	unsigned long nanoseconds_time;
}				t_data;

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
void 	get_collectibles(t_data *game);
void 	print_texture(t_data *game, void *img, int x, int y);
char 	*generate_player_path(int nb);
void	print_player(t_data *game, t_list *start, int x, int y);
void	load_player_textures(t_data *game);
void	ft_usleep(unsigned int microseconds);
void	recursive_workload(int count);
void	remove_collectible(t_data *g, int x, int y);

// movement
void	move_player(t_data *game, int action);
void	handle_movement(t_data *g, int x, int y, int action);
void	move_on_map(t_data *g, int *signal, int x, int y);
void	handle_end(t_data *g, int x, int y);

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}			t_window;

typedef struct s_image
{
	t_window win;
	void	*img_ptr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}				t_image;

t_window new_window(int w, int h, char *str);
t_image	 new_image(int w, int h, t_window win);
void	put_pixel_img(t_image img, int x, int y, int color);

#endif //SO_LONG_ENGINE_H
