/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:33:49 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 15:40:44 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pa(t_plist **stack_a, t_plist **stack_b, int trigger)
{
	t_plist	*element;
	t_plist	*temp;

	if (*stack_b == NULL)
		return ;
	element = *stack_b;
	*stack_b = element->next;
	if (*stack_a == NULL)
	{
		element->next = NULL;
		*stack_a = element;
	}
	else
	{
		temp = *stack_a;
		*stack_a = element;
		element->next = temp;
	}
	if (trigger == 1)
		ft_printf("pa\n");
	update_info(stack_a, 'a');
	update_info(stack_b, 'b');
}

void	pb(t_plist **stack_a, t_plist **stack_b, int trigger)
{
	t_plist	*element;
	t_plist	*temp;

	if (*stack_a == NULL)
		return ;
	element = *stack_a;
	*stack_a = element->next;
	if (*stack_b == NULL)
	{
		element->next = NULL;
		*stack_b = element;
	}
	else
	{
		temp = *stack_b;
		*stack_b = element;
		element->next = temp;
	}
	if (trigger == 1)
		ft_printf("pb\n");
	update_info(stack_a, 'a');
	update_info(stack_b, 'b');
}
