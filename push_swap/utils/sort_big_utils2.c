/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:57:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 16:31:30 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function rotates the stack until we have the bf_val value at the top
// of this stack, it also helps the algorithm determine the kind of rotation it
// has to apply to the list, if our count is greater than half of the size
// of the list it means that its more efficient to reverse rotate the list
// instead of just rotating (same logic as count_moves)
// This function ONLY rotates the B stack
void	put_b_on_top(t_plist **stack, int length, int bf_val)
{
	int		count;
	t_plist	*curr;

	if (*stack == NULL)
		return ;
	count = 0;
	curr = *stack;
	while (curr->data != bf_val)
	{
		count++;
		curr = curr->next;
	}
	if (count > (length / 2))
	{
		count = length - count;
		while (count-- != 0)
			rrb(stack, 1);
	}
	else
		while (count-- != 0)
			rb(stack, 1);
}

// This function rotates the stack until we have the bf_val value at the top
// of this stack, it also helps the algorithm determine the kind of rotation it
// has to apply to the list, if our count is greater than half of the size
// of the list it means that its more efficient to reverse rotate the list
// instead of just rotating (same logic as count_moves)
// This function ONLY rotates the A stack
void	put_a_on_top(t_plist **stack, int length, int bf)
{
	int		count;
	t_plist	*curr;

	if (*stack == NULL)
		return ;
	count = 0;
	curr = *stack;
	while (curr->data != bf)
	{
		count++;
		curr = curr->next;
	}
	if (count > (length / 2))
	{
		count = length - count;
		while (count-- != 0)
			rra(stack, 1);
	}
	else
		while (count-- != 0)
			ra(stack, 1);
}
