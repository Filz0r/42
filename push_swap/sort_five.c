/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/25 17:19:12 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_five(t_plist **root_a, t_plist **root_b)
{
	if ((*root_a)->next->data == (*root_a)->info->smallest_in_stack)
		sa(root_a, 1);
	else if ((*root_a)->data != (*root_a)->info->smallest_in_stack)
		while ((*root_a)->data != (*root_a)->info->smallest_in_stack)
			ra(root_a, 1);
	pb(root_a, root_b, 1);
	if ((*root_a)->info->stack_size == 3)
	{
		sort_three(root_a, 1);
		pa(root_a, root_b, 1);
		pa(root_a, root_b, 1);
	}
	else
		sort_five(root_a, root_b);
}
