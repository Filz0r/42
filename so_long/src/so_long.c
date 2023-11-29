/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/29 14:53:00 by fparreir         ###   ########.fr       */
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
			return (1);
		}
		game_run(game, "so_long");
		free(game);
		free_map(map);
	}
	else
	{
		printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
