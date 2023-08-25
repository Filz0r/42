/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:26:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/25 16:41:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

// else handles this case (first->data > second->data && second->data > third->data)
static int	case_check(t_plist **start)
{
	t_plist	*first;
	t_plist	*second;
	t_plist	*third;

	first = *start;
	second = (*start)->next;
	third = second->next;
	if (first->data < second->data && second->data > third->data
		&& first->data < third->data)
		return (1);
	else if (first->data > second->data && second->data < third->data
		&& first->data < third->data)
		return (2);
	else if (first->data < second->data && second->data > third->data)
		return (3);
	else if (first->data > second->data && second->data < third->data)
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
	if (case_check(stack) == 1)
	{
		rra(stack, 1);
		sa(stack, 1);
	}
	else if (case_check(stack) == 2)
		sa(stack, 1);
	else if (case_check(stack) == 3)
		rra(stack, 1);
	else if (case_check(stack) == 4)
		ra(stack, 1);
	else if (case_check(stack) == 5)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
}
