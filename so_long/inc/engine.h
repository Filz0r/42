/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:35:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/26 23:56:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# define CYCLE		350000000
# define SIZE		32
# define FLOOR_PATH	"assets/floor.xpm"
# define WALL_PATH	"assets/wall.xpm"
# define EXIT_PATH	"assets/exit.xpm"
# define COLL_PATH	"assets/collectible.xpm"
# define WALK_PATH	"assets/player/walking/"
# define IDLE_PATH	"assets/player/idle/"
# define DIE_PATH	"assets/player/dying/"

// Library stuff
void	*game_init(char **map, const char *name);
void	*game_cleanup(void *ptr); //todo: this is bugged and causes segfault
void	game_run(void *ptr);

#endif //ENGINE_H
