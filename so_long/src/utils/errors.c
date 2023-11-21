/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:39:21 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/21 11:23:54 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

// This function frees everything inside the map pointer and
// prints error messages.
void	errors(char **map, int code)
{
	free_map(map);
	if (code == 0)
	{
		ft_printf("Error\nThere was an issue allocating memory ");
		ft_printf("for the program\n");
	}
	else if (code == 1)
		ft_printf("Error\nThe map you provided has an invalid extension\n");
	else if (code == 2)
		ft_printf("Error\nThere are invalid char in your map!\n");
	else if (code == 3)
	{
		ft_printf("Error\nThe map either has multiple Exits and Players\n");
		ft_printf("Or the Map doesn't have 1 Exit, 1 Player ");
		ft_printf("and at least 1 Collectible!\n");
	}
	else if (code == 4)
		ft_printf("Error\nThe map is not rectangular!\n");
	else if (code == 5)
		ft_printf("Error\nThe map isn't walled of!\n");
	else if (code == 6)
		ft_printf("Error\nThe player cannot complete the map!\n");
}

// This function frees the map pointer, and anything inside it, however
// it might cause issues if by any reason the program fails to allocate
//  memory for the map.
void	free_map(char **map)
{
	char	**temp;
	int		i;

	i = 0;
	if (!map || !(*map))
		return ;
	temp = map;
	while (temp[i] != 0)
		free(temp[i++]);
	free(temp);
	*map = NULL;
}
