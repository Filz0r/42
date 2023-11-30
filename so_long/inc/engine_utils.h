/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:33:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/30 01:05:18 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_UTILS_H
# define ENGINE_UTILS_H

# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/includes/libft.h"
# include <time.h>

# define UP			1
# define DOWN		2
# define LEFT		3
# define RIGHT		4

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
	int		x;
	int		y;
	double	relative_x;
	double	relative_y;
}				t_point;


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
	t_list			*images;
	t_map			*map;
	t_img			*overlay;
	t_entity		last;
	t_entity		current;
	int				mirror;
	struct timespec	sleep_time;
	unsigned long	tick;
	unsigned long	frames;
	unsigned long	ns_time;
}				t_game;

typedef struct s_frame {
	t_list			*frames;
	t_entity		type;
	int				total_frames;
	int				current_frame;
}				t_frame;

// game stuff
int				quit_game(t_game *game);


// Map stuff
int				get_map_width(char **map);
int				get_map_height(char **map);
void			get_collectibles(char **map, t_list **lst);
t_map			*load_map(char **map);
t_point			*get_point(char **map, char to_find);

// Rendering stuff
void			render_frame(t_game *game, t_entity animation);
void			put_image_to_overlay(t_img *src, t_game *g,
					t_entity type, t_point pos);
unsigned int	get_pixel_img(t_img *img, int x, int y);
void			put_pixel_img(t_img *img, int x, int y, int color);
t_img			*create_overlay(t_window *w);
void			select_asset_to_put(t_game *game, char c, t_point pos);
void			handle_player_render(t_game *game, t_entity animation);
void			render_other_assets(t_game *game);
void			remove_collectible(t_game *g, t_point norm_point);

// Movement
int				move_player(t_game *game, int action);
int				check_collision(t_game *g, int x, int y, int action);
int				on_keypress(int keysym, t_game *game);
void			handle_restof_movement(t_game *g, t_point norm_point,
					int x, int y);

// Window stuff
void			load_assets(t_window *win, t_list **lst);
t_img			*create_image(char *path, t_window *win);
void			load_frames(t_window *w, t_list **lst, char *path, int size);
t_frame			*create_frame(t_window *w,
					char *asset_path, t_entity type, int frame_num);
t_window		*new_window(int width, int height, char *name);

// Memory cleaning TODO: this is bugged and segfaults
void			*map_cleanup(t_map *res);
void			*window_cleanup(t_window *w);
void			*images_cleanup(t_list *lst);
void			destroy_image(void *ptr);
void			destroy_frame(void *ptr);


//Utils
t_frame			*find_frame_by_entity(t_list *images, t_entity entity);
t_img			*get_img_by_entity(t_list *lst, t_entity entity);
t_point			normalize_point(t_point pt, double threshold_x,
					double threshold_y);
int				normalize(double nb, double threshold);

// Debugging functions not used in running code
void			print_time_status(t_game *g, struct timespec *last_tick);

#endif