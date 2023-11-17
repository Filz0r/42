/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/16 17:12:19 by fparreir         ###   ########.fr       */
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
		game.mlx_ptr = mlx_init();
		if (!game.mlx_ptr)
			return (1);
		game.win_ptr = mlx_new_window(game.mlx_ptr, \
		600, 400, "Will you work??");
		if (!game.win_ptr)
			return (free(game.mlx_ptr), 1);
		mlx_destroy_window(game.mlx_ptr, game.win_ptr);
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	else
	{
		ft_printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
