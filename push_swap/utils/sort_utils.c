/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:54:02 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 14:25:39 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//Finds the largest number on the stack we pass to the function and returns it
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

//Finds the smallest number on the stack we pass to the function and returns it
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

// Finds the smallest and biggest numbers of the passed stack and updates the
// info pointer of the passed stack so that it contains these values
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

// Initializes the info pointer that we use to keep track of the needed
// information to implement the algorithm.
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
		curr->info = new;
		curr = curr->next;
	}
	set_smallest_and_biggest(start);
}

// Updates the info pointer after we make a move on the stack
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
