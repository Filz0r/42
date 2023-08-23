/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:26:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 17:16:28 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static int	case_check(t_plist **start)
{
	t_plist	*first;
	t_plist	*second;
	t_plist	*third;

	first = *start;
	second = (*start)->next;
	third = second->next;
	if (first->info->curr_pos == first->info->final_pos
		&& second->info->curr_pos == (second->info->final_pos - 1))
		return (1);
	else if (first->info->final_pos == (first->info->stack_size - 1)
		&& second->info->final_pos == second->info->curr_pos)
		return (2);
	else if ((first->info->curr_pos + 1) == first->info->final_pos
		&& (second->info->curr_pos + 1) == second->info->final_pos)
		return (3);
	else if (third->info->curr_pos == third->info->final_pos
		&& first->data > second->data)
		return (4);
	else
		return (5);
}

void	sort_three(t_plist **stack, int size)
{
	if (size == 2)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack, 1);
		return ;
	}
	if (is_sorted(stack) == 1)
		return ;
	else if (case_check(stack) == 1)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (case_check(stack) == 2)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
	else if (case_check(stack) == 3)
		rra(stack, 1);
	else if (case_check(stack) == 4)
		sa(stack, 1);
	else if (case_check(stack) == 5)
		ra(stack, 1);
}
