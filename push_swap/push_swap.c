/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/13 23:38:14 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

int	main(int ac, char **av)
{
	t_plist	*root_a;
	t_plist	*root_b;

	root_a = NULL;
	root_b = NULL;
	if (ac >= 2)
	{
		handle_args(--ac, av, &root_a);
		info_init(&root_a);
		if (is_sorted(&root_a))
		{
			free_list(&root_a);
			return (0);
		}
		push_swap(&root_a, &root_b);
		free_list(&root_a);
		free_list(&root_b);
	}
	return (0); 
}

// This function is responsible for checking what algorithm is going to run
// depending on the amount of values passed
void	push_swap(t_plist **a, t_plist **b)
{
	if ((*a)->info->total_size <= 3)
		sort_three(a);
	else if ((*a)->info->total_size <= 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}

// Sorts lists with 3 elements
void	sort_three(t_plist **stack)
{
	t_plist	*curr;

	curr = *stack;
	if (curr->data == curr->info->smallest_in_stack)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (curr->data == curr->info->biggest_in_stack)
	{
		if (curr->next->data == curr->info->smallest_in_stack)
			ra(stack, 1);
		else
		{
			sa(stack, 1);
			rra(stack, 1);
		}
	}
	else
	{
		if (curr->next->data == curr->info->smallest_in_stack)
			sa(stack, 1);
		else
			rra(stack, 1);
	}
}

// Sorts lists with 5 elements
void	sort_five(t_plist **root_a, t_plist **root_b)
{
	if ((*root_a)->next->data == (*root_a)->info->smallest_in_stack)
		sa(root_a, 1);
	else
		while ((*root_a)->data != (*root_a)->info->smallest_in_stack)
			rra(root_a, 1);
	pb(root_a, root_b, 1);
	if ((*root_a)->info->stack_size == 3)
	{
		if (!(is_sorted(root_a)))
			sort_three(root_a);
		pa(root_a, root_b, 1);
		pa(root_a, root_b, 1);
	}
	else
		sort_five(root_a, root_b);
}

// Sorts lists with more than 5 elements
// First we find the mean value of the elements inside the list
// Then we push all of the values bellow this mean value to the B stack
// until the A stack only has 5 elements
// Finally we sort the 5 elements inside the A stack using sort_five
// Then we enter a loop that will run until the B stack points to NULL again
// (meaning its empty)
// In this loop we start by looking for the value that as the smallest cost
// of sorting, after finding this value
// we look for the value that is its best_friend inside the A stack.
// (bf_val is the value stored in B stack)
// Finally we put our bf_value on top of the B stack, and do the
// same for the A stack
// (won't do anything if BF is already at the top)
// And we push the bf_val node from the B stack to the A stack
// Again this is done until the B stack is null.
// after this loop we rotate the list until the smallest number
// is at the top of the A stack.
void	sort_big(t_plist **a, t_plist **b)
{
	int	mean;
	int	bf_val;
	int	bf;

	while ((*a)->info->stack_size != 5)
	{
		mean = get_mean_number(a);
		if ((*a)->data <= mean)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
	sort_five(a, b);
	while (*b != NULL)
	{
		bf_val = get_lowest_cost(a, b);
		bf = get_bf(a, bf_val);
		put_b_on_top(b, (*b)->info->stack_size, bf_val);
		put_a_on_top(a, (*a)->info->stack_size, bf);
		pa(a, b, 1);
	}
	while ((*a)->data != (*a)->info->smallest_in_stack)
		ra(a, 1);
}
