/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:21 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/15 16:42:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	errors(t_data *game, int code)
{
	free_game(game);
	if (code == 0)
		ft_printf("Error\nThere was an issue allocating memory for the program");
}

//TODO: add check for null
void	free_game(t_data *game)
{
	char	**temp;
	int		i;

	i = 0;
	temp = game->map->map;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
	free(game->map->player);
	free(game->map->exit);
	free(game->map);
	free(game);
}
