/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 11:59:14 by fparreir         ###   ########.fr       */
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
		print_list_long(&root_a); // remove later
		free(array);

		sort_three(&root_a, &root_b);
		//something like that freees the data
		// the errors function should also call this function when something
		// goes wrong with the program, to avoid leaks.
		//free_list(&root_a);
		//free_list(&root_b);
	}
	return (0); 
}
