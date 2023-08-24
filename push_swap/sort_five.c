/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:56:40 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/24 17:22:51 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

static void	rule_handle_four(t_plist **a, t_plist **b)
{
	t_plist	*last;
	t_plist	*second_last;

	last = get_last(a);
	second_last = get_second_last(a);
	if ((*b)->data < (*a)->data)
		pa(a, b, 1);
	else if ((*b)->data > last->data)
	{
		pa(a, b, 1);
		ra(a, 1);
	}
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
	{
		pa(a, b, 1);
		sa(a, 1);
	}
	else if (last->data > (*b)->data && (*b)->data > second_last->data)
	{
		rra(a, 1);
		pa(a, b, 1);
		ra(a, 1);
		ra(a, 1);
	}
}

void	handle_five_fnorm(t_plist **a, t_plist **b, t_plist *sl, t_plist *l)
{
	t_plist	*first;
	t_plist	*second;

	first = *a;
	second = first->next;
	print_list(a);
	print_list(b);
	if ((*b)->data > first->data && (*b)->data < sl->data
		&& second->data < (*b)->data)
	{
		rra(a, 1);
		pa(a, b, 1);
		ra(a, 1);
		ra(a, 1);
	}
	else if ((*b)->data < first->data)
		pa(a, b, 1);
	else if ((*b)->data > first->data && (*b)->data < second->data)
	{
		pa(a, b, 1);
		sa(a, 1);
	}
	else if ((*))
}

static void	handle_five_final(t_plist **a, t_plist **b)
{
	t_plist	*last;
	t_plist	*second_last;

	last = get_last(a);
	second_last = get_second_last(a);
	if ((*b)->data > last->data)
	{
		pa(a, b, 1);
		ra(a, 1);
	}
	else if ((*b)->data < last->data && (*b)->data > second_last->data)
	{
		ra(a, 1);
		ra(a, 1);
		pa(a, b, 1);
		rra(a, 1);
		rra(a, 1);
	}
	else
		return (handle_five_fnorm(a, b, second_last, last));
}

static void	rule_handle_five(t_plist **a, t_plist **b)
{
	t_plist	*last;
	t_plist	*second_last;

	last = get_last(a);
	second_last = get_second_last(a);
	if ((*b)->data < (*a)->data)
		pa(a, b, 1);
	else if ((*b)->data > last->data)
	{
		pa(a, b, 1);
		ra(a, 1);
	}
	else if ((*b)->data > (*a)->data && (*b)->data < (*a)->next->data)
	{
		pa(a, b, 1);
		sa(a, 1);
	}
	else if (last->data > (*b)->data && (*b)->data > second_last->data)
	{
		rra(a, 1);
		pa(a, b, 1);
		ra(a, 1);
		ra(a, 1);
	}
	handle_five_final(a, b);
}

void	sort_five(t_plist **root_a, t_plist **root_b, int size)
{
	if (is_sorted(root_a))
		return ;
	if (size == 4)
	{
		pb(root_a, root_b, 1);
		sort_three(root_a, 3);
		rule_handle_four(root_a, root_b);
	}
	else
	{
		pb(root_a, root_b, 1);
		pb(root_a, root_b, 1);
		sort_three(root_a, 3);
		rule_handle_five(root_a, root_b);
	}
}
