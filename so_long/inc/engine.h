/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 10:35:15 by fparreir         ###   ########.fr       */
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

typedef enum e_entity {
	PLAYER,
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
	t_rpoint	*r_curr;
	t_rpoint	last;
}			t_player;

typedef struct s_map {
	char	**map;
	t_point	*player;
	t_point	*start;
	t_point	*exit;
	t_list	*collectibles;
	int		width;
	int		height;
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

void	*game_init(char **map, const char *name);

#endif //ENGINE_H
