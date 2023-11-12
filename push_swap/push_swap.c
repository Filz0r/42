/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/12 10:54:49 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int ac, char **av)
{
	t_plist	*root_a;
	t_plist	*root_b;

	root_a = NULL;
	root_b = NULL;
	if (ac >= 2)
	{
		handle_args(--ac, av, &root_a);
		info_init(&root_a);
		if (is_sorted(&root_a))
		{
			free_list(&root_a);
			return (0);
		}
		push_swap(&root_a, &root_b);
		free_list(&root_a);
		free_list(&root_b);
	}
	return (0); 
}

void push_swap(t_plist **a, t_plist **b)
{
	if ((*a)->info->total_size == 3)
		sort_three(a, (*a)->info->total_size);
	else if ((*a)->info->total_size == 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}
