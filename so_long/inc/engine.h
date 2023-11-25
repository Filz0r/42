/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/24 21:59:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

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

// Library stuff
void	*game_init(char **map, const char *name);
void	*game_cleanup(void *ptr);
void	*game_run(void *ptr);

#endif //ENGINE_H
