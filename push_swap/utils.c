/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:25 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/21 16:34:18 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*handle_args(int counter, char **values, t_plist **start)
{
	int	i;
	int k;
	int	*array;

	i = 1;
	while (i <= counter)
		add_list_end(start, ft_atoi(values[i++]));
	i = 0;
	k = 1;
	array = malloc(sizeof(int) * counter);
	while (k <= (counter))
	{
		array[i++] = ft_atoi(values[k++]);
	}
	return (array);
}

void	errors(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(2);
}
