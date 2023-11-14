/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 14:58:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/12 10:54:49 by fparreir         ###   ########.fr       */
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

void push_swap(t_plist **a, t_plist **b)
{
	if ((*a)->info->total_size == 3)
		sort_three(a);
	else if ((*a)->info->total_size == 5)
		sort_five(a, b);
	else
		sort_big(a, b);
}

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
