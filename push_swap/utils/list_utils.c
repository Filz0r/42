/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:19:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 10:52:09 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	add_list_end(t_plist **start, int num)
{
	t_plist	*new_node;
	t_plist	*curr;

	new_node = malloc(sizeof(t_plist));
	if (new_node == NULL)
		errors();
	new_node->data = num;
	new_node->pos = -1;
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

size_t	list_length(t_plist **start)
{
	size_t	i;
	t_plist	*curr;

	i = 0;
	if (*start == NULL)
		return (i);
	curr = *start;
	while (curr)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

void	set_list_positions(t_plist **start, int *array, int array_size)
{
	t_plist	*curr;
	int		index;

	if (*start == NULL)
		return ;
	curr = *start;
	while (curr)
	{
		index = get_array_index(array, array_size, curr->data);
		if (index < 0)
			errors();
		curr->pos = index;
		curr = curr->next;
	}
}
