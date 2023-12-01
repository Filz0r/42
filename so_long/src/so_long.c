/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/01 22:26:21 by fparreir         ###   ########.fr       */
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
		if (!game) // TODO: test this or remove
		{
			free(game);
			free_map(map);
			return (1);
		}
		game_run(game, "so_long");
	}
	else
	{
		printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
