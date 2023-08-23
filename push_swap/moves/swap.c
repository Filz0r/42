/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:21:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 10:31:24 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_plist **stack_a, int trigger)
{
	//logic goes above
	if (trigger == 1)
		ft_printf("sa\n");
}

void	sb(t_plist **stack_b, int trigger)
{
	//logic goes above
	if (trigger == 1)
		ft_printf("sb\n");
}

void	ss(t_plist **stack_a, t_plist **stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("ss\n");
}
