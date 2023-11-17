/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/17 12:01:58 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int on_destroy(t_data *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	return (0);
}

int on_keypress(int keysym, t_data *game)
{
	(void)game;
	printf("pressed: %d\n", keysym);
	return (0);
}

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
		600, 400, "so_long");
		if (!game.win_ptr)
			return (free(game.mlx_ptr), 1);

		mlx_hook(game.mlx_ptr, KeyRelease, KeyReleaseMask,&on_keypress, &game);
		mlx_hook(game.mlx_ptr, DestroyNotify, StructureNotifyMask, &on_destroy, &game);

		mlx_loop(game.mlx_ptr);

	}
	else
	{
		ft_printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
