/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/21 17:33:25 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	int		*array;
	t_plist	*root_a;
	//t_plist	*root_b;

	root_a = NULL;
	//root_b = NULL;
	array = NULL;
	if (ac >= 2)
	{
		array = handle_args(--ac, av, &root_a);
		print_list(&root_a);
		bubble_sort(array, ac);
		print_array(array, ac);
		print_list_long(&root_a);
		set_list_positions(&root_a, array, ac);
		print_list_long(&root_a);
	}
	return (0); 
}
