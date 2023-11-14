/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:33:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 16:58:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Places the last element of A stack on the top of the stack
void	rra(t_plist **stack_a, int trigger)
{
	t_plist	*last;
	t_plist	*second_last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	second_last = *stack_a;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack_a;
	second_last->next = NULL;
	*stack_a = last;
	if (trigger == 1)
		ft_printf("rra\n");
	update_info(stack_a, 'a');
}

// Places the last element of B stack on the top of the stack
void	rrb(t_plist **stack_b, int trigger)
{
	t_plist	*last;
	t_plist	*second_last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	second_last = *stack_b;
	while (second_last->next->next)
		second_last = second_last->next;
	last = second_last->next;
	last->next = *stack_b;
	second_last->next = NULL;
	*stack_b = last;
	if (trigger == 1)
		ft_printf("rrb\n");
	update_info(stack_b, 'b');
}

// Places the last element of both stacks to the top
void	rrr(t_plist **stack_a, t_plist **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rrr\n");
}
