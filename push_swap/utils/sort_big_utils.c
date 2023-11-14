/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:35:46 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 12:35:46 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function is what finds out what is the node of our list we want to bring
// to the top in order to put next to its best-friend.
// It does so by going through all the elements inside the B stack, and then for
// each element in the B stack we look for its best friend located in the A
// stack, and we calculate the amount of moves it would take to place this node
// and its best friend on top of the corresponding stacks, we do this until the
// end of the list and along the way we try to find the number with the smallest
// cost so that we can return it to the sort_big function so that it can then
// once again find the BF of the return of the function, and it places both
// elements at the top of their corresponding lists before pushing the
// element from the B stack back to the A stack.
// We use INT_MAX because we want ALWAYS to use the smallest number and by
// doing this we make sure that if the current node we are looking at is the
// largest value in the stack we are able to overwrite it as the algorithm runs
int	get_lowest_cost(t_plist **a, t_plist **b)
{
	t_plist	*curr;
	int		bf;
	int		lowest_cost;
	int		cost;
	int		best_nb;

	lowest_cost = INT_MAX;
	curr = *b;
	while (curr)
	{
		bf = get_bf(a, curr->data);
		cost = get_cost(a, b, bf, curr->data);
		if (cost <= lowest_cost)
		{
			best_nb = curr->data;
			lowest_cost = cost;
		}
		curr = curr->next;
	}
	return (best_nb);
}

// We look for the best friend of the passed value to achieve this we
// look for the biggest number inside our stack that is also bigger
// than the number we passed, but at the same time we want to always
// be able to overwrite the default bf value of this function.
// We use INT_MAX again as our starting value so that we can overwrite
// this value in the event the current node we are in is smaller than
// the value we have currently saved as our bf variable, but at the
// same time is smaller than the bf_val we pass to the function.
int	get_bf(t_plist **a, int bf_val)
{
	t_plist	*curr;
	int		bf;

	bf = INT_MAX;
	curr = *a;
	while (curr)
	{
		if (curr->data > bf_val && bf >= curr->data)
			bf = curr->data;
		curr = curr->next;
	}
	return (bf);
}

// Calculates the total cost of moving both nodes to the top
int	get_cost(t_plist **a, t_plist **b, int bf, int current)
{
	int	moves;

	moves = count_moves(a, (*a)->info->stack_size, bf);
	moves += count_moves(b, (*b)->info->stack_size, current);
	return (moves);
}

// calculates the total cost of moving a singular node to the top
// if it returns a negative value it means that its more efficient
// to rotate the list in the inverse order, this logic is also
// used when we start rotating the chosen values to the top of their lists
// this makes it so that if the algorithm determines that a negative rotation
// is better it will chose this number as bf based of this.
int	count_moves(t_plist **start, int length, int value)
{
	int		count;
	t_plist	*current;

	count = 0;
	current = *start;
	while (current->data != value)
	{
		count++;
		current = current->next;
	}
	if (count > (length / 2))
		return (length - count);
	return (count);
}
