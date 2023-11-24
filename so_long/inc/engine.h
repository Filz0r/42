/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 15:52:14 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>

# define CYCLE		10000000000
# define SIZE		32
# define UP			1
# define DOWN		2
# define LEFT		3
# define RIGHT		4
# define FLOOR_PATH	"assets/floor.xpm"
# define WALL_PATH	"assets/wall.xpm"
# define EXIT_PATH	"assets/exit.xpm"
# define COLL_PATH	"assets/collectible.xpm"
# define WALK_PATH	"assets/player/walking/"
# define IDLE_PATH	"assets/player/idle/"
# define DIE_PATH	"assets/player/dying/"

typedef enum e_entity {
	PLAYER_IDLE,
	PLAYER_WALKING,
	PLAYER_DYING,
	FLOOR,
	WALL,
	COLLECTIBLE,
	EXIT
}			t_entity;

typedef struct s_point {
	int	x;
	int	y;
}				t_point;

typedef struct s_rpoint {
	float	x;
	float	y;
}				t_rpoint;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width;
	int		height;
}			t_window;

typedef struct s_img {
	t_window	*win;
	void		*img_ptr;
	char		*addr;
	int			h;
	int			w;
	int			bpp;
	int			endian;
	int			line_len;
}			t_img;

typedef struct s_frame {
	t_list			*frames;
	t_entity		type;
	int				total_frames;
	int				current_frame;
	unsigned long	delay;
	unsigned long	last_updated;
}				t_frame;

typedef struct s_player {
	t_list		*walking;
	t_list		*dying;
	t_list		*idle;
	t_point		start;
	t_point		*current;
	//t_rpoint	*r_curr;
	//t_rpoint	last;
}			t_player;

typedef struct s_map {
	char	**map;
	t_point	*player;
	t_point	*start;
	t_point	*exit;
	t_list	*collectibles;
	int		width;
	int		height;
	int		col_count;
}	t_map;

typedef struct s_game {
	t_window		*win;
	t_player		*player;
	t_map			*map;
	t_list			*images;
	unsigned long	tick;
	unsigned long	frames;
	unsigned long	ns_time;
}				t_game;

// Library stuff
void			*game_init(char **map, const char *name);
void			*game_cleanup(void *ptr);

// Map stuff
int				get_map_width(char **map);
int				get_map_height(char **map);
void			get_collectibles(char **map, t_list **lst);
void			*map_cleanup(t_map *res);
t_map			*load_map(char **map);
t_point			*get_point(char **map, char to_find);


// Window stuff
void			put_pixel_img(t_img img, int x, int y, int color);
void			load_assets(t_window *win, t_list **lst);
void			*window_cleanup(t_window *window);
void			*images_cleanup(t_list *lst);
unsigned int	get_pixel_img(t_img img, int x, int y);
t_img			*create_image(char *path, t_window *win);
t_list			*load_frames(t_window *w, char *path, int size);
t_frame			*create_frame(t_window *w,
					char *asset_path, t_entity type, int frame_num);
t_window		*new_window(int width, int height, char *name);

// Player stuff
t_player		*load_player(t_game *ptr);

#endif //ENGINE_H
