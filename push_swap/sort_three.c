/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:26:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 11:19:47 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"


void	sort_three(t_plist **stack_a, t_plist **stack_b)
{
	t_plist	*curr;

	if (*stack_a == NULL || *stack_b != NULL)
		errors();
	curr = *stack_a;
	while (curr)
	{

		curr = curr->next;
	}

}