/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:26:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 12:52:11 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


void	sort_three(t_plist **stack_a, t_plist **stack_b)
{
	if (*stack_a == NULL || *stack_b != NULL)
		errors();

	rra(stack_a, 1);
	ft_printf("====================\n");
	print_list_long(stack_a);
}
