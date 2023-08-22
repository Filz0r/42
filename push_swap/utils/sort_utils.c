/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 10:54:02 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 12:51:45 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	initialize_move_counters(t_plist **start)
{
	t_plist	*curr;

	if (*start == NULL)
		errors();
	curr = *start;
	while (curr)
	{
		curr->info->pa = -1;
		curr->info->pb = -1;
		curr->info->sa = -1;
		curr->info->sb = -1;
		curr->info->ra = -1;
		curr->info->rb = -1;
		curr->info->rra = -1;
		curr->info->rrb = -1;
		curr = curr->next;
	}
}

void	info_init(t_plist **start, int *array, int size)
{
	t_plist	*curr;
	t_info	*new;
	int		i;

	if (*start == NULL)
		errors();
	i = 0;
	curr = *start;
	while (curr)
	{
		new = malloc(sizeof(t_info));
		if (!new)
			errors();
		new->parent = curr;
		new->stack = 'a';
		new->stack_size = size;
		new->final_pos = get_array_index(array, size, curr->data);
		new->curr_pos = i;
		i++;
		curr->info = new;
		curr = curr->next;
	}
	initialize_move_counters(start);
}
