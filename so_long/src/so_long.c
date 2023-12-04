/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/04 15:28:20 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/engine.h"

// The program has 2 parts the engine and the map parser/validator,
int	main(int ac, char **av)
{
	char	**map;
	void	*game;

	if (ac == 2)
	{
		map = validate_map(av[1]);
		if (!map || *map == NULL)
			return (1);
		game = game_init(map);
		if (!game)
		{
			free(game);
			free_map(map);
			return (1);
		}
		game_run(game, "so_long");
	}
	else
	{
		ft_printf("%sError:%s Incorrect usage.\n"
			"Correct usage: ./so_long /path/to/map.ber\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
