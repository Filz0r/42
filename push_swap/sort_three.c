/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:26:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 08:07:34 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_three(t_plist **stack_a, t_plist **stack_b, int *array, int size)
{
	int			current_position;
	t_plist		*curr;

	if (*stack_a == NULL || *stack_b != NULL)
		errors();
	curr = *stack_a;
	while (curr)
	{
		current_position = get_current_position();
		curr = curr->next;
	}
}