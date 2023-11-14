/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:54:02 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/25 16:10:20 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_largest(t_plist **start)
{
	t_plist	*curr;
	int		res;

	res = INT_MIN;
	curr = *start;
	while (curr)
	{
		if (curr->data > res)
			res = curr->data;
		curr = curr->next;
	}
	return (res);
}

int	get_smallest(t_plist **start)
{
	t_plist	*curr;
	int		res;

	res = INT_MAX;
	curr = *start;
	while (curr)
	{
		if (curr->data < res)
			res = curr->data;
		curr = curr->next;
	}
	return (res);
}

void	set_smallest_and_biggest(t_plist **start)
{
	t_plist	*curr;
	int		small;
	int		big;

	curr = *start;
	small = get_smallest(start);
	big = get_largest(start);
	while (curr)
	{
		curr->info->smallest_in_stack = small;
		curr->info->biggest_in_stack = big;
		curr = curr->next;
	}
}

void	info_init(t_plist **start)
{
	t_plist	*curr;
	t_info	*new;
	int		size;

	size = list_size(start);
	if (*start == NULL)
		errors(start);
	curr = *start;
	while (curr)
	{
		new = malloc(sizeof(t_info));
		if (!new)
			errors(start);
		new->stack = 'a';
		new->stack_size = size;
		new->total_size = size;
		new->parent = curr;
		new->bf = NULL;
		curr->info = new;
		curr = curr->next;
	}
	set_smallest_and_biggest(start);
}

void	update_info(t_plist **start, char stack)
{
	int		i;
	t_plist	*curr;

	i = 0;
	curr = *start;
	while (curr)
	{
		if (curr->info->stack != stack)
			curr->info->stack = stack;
		i++;
		curr = curr->next;
	}
	curr = *start;
	while (curr)
	{
		curr->info->stack_size = i;
		curr = curr->next;
	}
	set_smallest_and_biggest(start);
}
