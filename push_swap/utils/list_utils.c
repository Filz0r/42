/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:19:37 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/23 12:55:13 by fparreir         ###   ########.fr       */
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

int	is_num_in_stack(t_plist **start, int nb)
{
	t_plist	*curr;

	if (*start == NULL)
		return (0);
	curr = *start;
	while (curr)
	{
		if (curr->data == nb)
			return (1);
		curr = curr->next;
	}
	return (0);
}
