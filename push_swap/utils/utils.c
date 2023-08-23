/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:25 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 12:55:02 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*handle_args(int counter, char **values, t_plist **start)
{
	int	i;
	int	k;
	int	nb;
	int	*array;

	i = 1;
	while (i <= counter)
	{
		nb = ft_atoi(values[i++]);
		if (is_num_in_stack(start, nb) == 1)
			errors();
		add_list_end(start, nb);
	}
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
