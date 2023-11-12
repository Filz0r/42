/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 16:57:22 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/11 22:08:50 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_big(t_plist **a, t_plist **b)
{
	int	mean;
//	int	bf;
//	int	bf_val;

	print_list(a);
	print_list(b);
	//push below mean
	while ((*a)->info->stack_size != 5)
	{
		mean = get_mean_number(a);
		if ((*a)->data <= mean)
			pb(a, b, 1);
		else
			ra(a, 1);
	}

	printf("========================\n");
	sort_five(a, b);
	printf("========================\n");

	print_list(a);
	print_list(b);
}
