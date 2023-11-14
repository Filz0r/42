/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:19:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 11:52:21 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Adds a node to the end of the Linked List structure
// (this makes it so that the arguments are added in order)
void	add_list_end(t_plist **start, int num)
{
	t_plist	*new_node;
	t_plist	*curr;

	new_node = malloc(sizeof(t_plist));
	if (new_node == NULL)
		errors(start);
	new_node->data = num;
	new_node->info = NULL;
	new_node->next = NULL;
	if (*start == NULL)
	{
		*start = new_node;
		return ;
	}
	curr = *start;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

// Check is a list is sorted
int	is_sorted(t_plist **start)
{
	t_plist	*curr;
	t_plist	*next;

	curr = *start;
	while (curr->next)
	{
		next = curr->next;
		if (curr->data < next->data)
			curr = curr->next;
		else
			return (0);
	}
	return (1);
}

// Check if the nb value is inside the Linked List we pass
int	is_num_in_stack(t_plist **start, int nb)
{
	t_plist	*curr;

	if (*start == NULL)
		return (0);
	curr = *start;
	while (curr != NULL && curr)
	{
		if (curr->data == nb)
			return (1);
		curr = curr->next;
	}
	return (0);
}

// Checks the size of the Linked List
int	list_size(t_plist **start)
{
	t_plist	*curr;
	int		res;

	res = 0;
	if (*start == NULL)
		return (0);
	else
		curr = *start;
	while (curr)
	{
		res++;
		curr = curr->next;
	}
	return (res);
}
