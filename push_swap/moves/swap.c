/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:21:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 17:00:02 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swaps the first element of the A stack with the second element
void	sa(t_plist **stack_a, int trigger)
{
	t_plist	*first;
	t_plist	*second;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (trigger == 1)
		ft_printf("sa\n");
	update_info(stack_a, 'a');
}

// Swaps the first element of the B stack with the second element
void	sb(t_plist **stack_b, int trigger)
{
	t_plist	*first;
	t_plist	*second;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	if (trigger == 1)
		ft_printf("sb\n");
	update_info(stack_b, 'b');
}

// Swaps the first element of both stacks with the second element
void	ss(t_plist **stack_a, t_plist **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
