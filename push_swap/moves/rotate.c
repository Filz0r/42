/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:30:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 13:23:02 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(t_plist **stack_a, int trigger)
{
	t_plist	*first;
	t_plist	*second;
	t_plist	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	second = (*stack_a)->next;
	last = *stack_a;
	while (last->next != NULL)
		last = last->next;
	*stack_a = second;
	last->next = first;
	first->next = NULL;
	if (trigger == 1)
		ft_printf("ra\n");
}

void	rb(t_plist **stack_b, int trigger)
{
	t_plist	*first;
	t_plist	*second;
	t_plist	*last;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	second = (*stack_b)->next;
	last = *stack_b;
	while (last->next != NULL)
		last = last->next;
	*stack_b = second;
	last->next = first;
	first->next = NULL;
	if (trigger == 1)
		ft_printf("rb\n");
}

void	rr(t_plist **stack_a, t_plist **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}
