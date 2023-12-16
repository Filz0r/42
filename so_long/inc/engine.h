/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 15:31:44 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# ifndef PRINT_MOVES
#  define PRINT_MOVES	1
# endif

# ifndef KILL_PLAYER
#  define KILL_PLAYER	0
# endif

# ifndef FLOOD_MAX
#  define FLOOD_MAX		4
# endif

# ifndef FLOOD_SCALE
#  define FLOOD_SCALE	1
# endif

# define CYCLE			450000000
# define SECOND			1000000000
# define SIZE			32
# define FLOOR_PATH		"assets/floor.xpm"
# define WALL_PATH		"assets/wall.xpm"
# define EXIT_PATH		"assets/exit.xpm"
# define COLL_PATH		"assets/collectible.xpm"
# define WALK_PATH		"assets/player/walking/"
# define IDLE_PATH		"assets/player/idle/"
# define DIE_PATH		"assets/player/dying/"
# define DIGIT_PATH		"assets/digits/"
# define ENEMY_PATH		"assets/enemy/"

// Library stuff
void	*game_init(char **map);
void	*game_cleanup(void *ptr); //todo: this is bugged and causes segfault
void	*game_run(void *ptr, char *name);

#endif //ENGINE_H
