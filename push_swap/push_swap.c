/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:57:39 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/29 15:59:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
 
int	main(int ac, char **av)
{
	t_ps_list	stack;

	if (ac > 1)
	{
		stack = handle_args(--ac, av); 
		if (ac <= 5)
			sort_small(ac, stack);
		else
			sort_big(ac, stack);
	}
	else
		errors(0);
//	free(stack); 
	return (0); 
}
