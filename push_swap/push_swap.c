/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/24 11:23:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int ac, char **av)
{
	int		*array;
	t_plist	*root_a;
	t_plist	*root_b;

	root_a = NULL;
	root_b = NULL;
	array = NULL;
	if (ac >= 2)
	{
		array = handle_args(--ac, av, &root_a);
		bubble_sort(array, ac);
		info_init(&root_a, array, ac);
		ft_printf("before "); // remove later
		print_list(&root_a); // remove later
		free(array);
		if (ac <= 3)
			sort_three(&root_a, ac);
		else if (ac <= 5)
			sort_five(&root_a, &root_b, ac);
		//something like that freees the data
		// the errors function should also call this function when something
		// goes wrong with the program, to avoid leaks.
		//free_list(&root_a);
		//free_list(&root_b);
		ft_printf("after "); // remove later
		print_list_long(&root_a); // remove later
	}
	return (0); 
}
