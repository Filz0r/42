/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:33:11 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 10:33:18 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rra(t_plist **stack_a, int trigger)
{
	//logic goes above
	if (trigger == 1)
		ft_printf("ra\n");
}

void	rrb(t_plist **stack_b, int trigger)
{
	//logic goes above
	if (trigger == 1)
		ft_printf("rb\n");
}

void	rrr(t_plist **stack_a, t_plist **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	ft_printf("rr\n");
}