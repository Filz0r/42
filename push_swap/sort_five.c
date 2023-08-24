/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/24 11:33:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	rule_handle(t_plist **a, t_plist **b)
{

}

static void	handle_four(t_plist **stack_a, t_plist **stack_b)
{
	pb(stack_a, stack_b, 1);
	sort_three(stack_a, 3);
	rule_handle(stack_a, stack_b);
	print_list_long(stack_a);
	print_list_long(stack_b);
}

void	sort_five(t_plist **root_a, t_plist **root_b, int size)
{
	if (is_sorted(root_a))
		return ;
	if (size == 4)
		return (handle_four(root_a, root_b));
}
