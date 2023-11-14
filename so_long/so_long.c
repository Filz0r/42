/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 19:45:16 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 19:54:15 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int ac, char **av)
{
	int	i;

	i = -1;
	if (ac == 2)
	{
		while (av[++i])
			ft_printf("word n%d: %s\n", (i + 1), av[i]);
	}
	else
	{
		ft_printf("%sError that you need to handle idiot%s\n", RED, WHITE);
		exit(EXIT_FAILURE);
	}
	return (0);
}
