/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/20 19:23:51 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (ac == 2)
	{
		validate_map(av[1], &game);
		if (game.map == NULL)
			return (1);
		game.frames = 0;
		game.steps = 0;
		game.tile_size = TILE_SIZE;
		game.microseconds_time = (CYCLE_SIZE / FPS);
		game.img = malloc(sizeof(t_img));
		game_init(&game);
	}
	else
	{
		printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
