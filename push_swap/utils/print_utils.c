/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:27:33 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 13:06:56 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list(t_plist **start)
{
	t_plist	*curr;

	if (*start == NULL)
	{
		ft_printf("%sEmpty List%s\n", RED, WHITE);
		return ;
	}
	ft_printf("List: %s{ %s", PURPLE, WHITE);
	curr = *start;
	while (curr)
	{
		ft_printf("%s%d%s", BLUE, curr->data, WHITE);
		if (curr->next != NULL)
			ft_printf(", ");
		curr = curr->next;
	}
	ft_printf(" %s}\n%s", PURPLE, WHITE);
}

void	print_array(int *arr, int size)
{
	int	i;

	i = 0;
	ft_printf("%sArray:%s { ", GREEN, WHITE);
	while (i <= (size - 1))
	{
		ft_printf("%s%d%s", CYAN, arr[i], WHITE);
		if (i < (size - 1))
			ft_printf(", ");
		i++;
	}
	if (i == size)
		ft_printf(" }\n");
}

static void	print_info(t_plist *curr)
{
	if (curr == NULL || curr->info == NULL)
		return ;
	ft_printf("\n{\n\tcurr_pos:%s%d%s,\n" \
					"\tfinal_pos: %s%d%s\n" \
					"\tstack: %s%c%s,\n" \
					"\tssize: %s%d%s\n}\n", \
			GREEN, curr->info->curr_pos, WHITE, \
			GREEN, curr->info->final_pos, WHITE, \
			GREEN, curr->info->stack, WHITE, \
			GREEN, curr->info->stack_size, WHITE);
}

void	print_list_long(t_plist **start)
{
	t_plist	*curr;

	if (*start == NULL)
	{
		ft_printf("%sEmpty List%s\n", RED, WHITE);
		return ;
	}
	ft_printf("%sList: \n%s", PURPLE, WHITE);
	curr = *start;
	while (curr)
	{
		ft_printf("[ value: %s%d%s, info-p: %s%p%s", \
			YELLOW, curr->data, WHITE, GREEN, curr->info, WHITE);
		print_info(curr);
		ft_printf(", next: %s%p%s ]", CYAN, curr->next, WHITE);
		if (curr->next != NULL)
			ft_printf("\n");
		curr = curr->next;
	}
	ft_printf("\n%s", WHITE);
}

void	print_moves(t_plist **start)
{
	t_plist	*curr;

	if (*start == NULL)
		errors();
	curr = *start;
	while (curr)
	{
		if (curr->info != NULL)
		{
			ft_printf("%sMOVES FOR %p:\n%s", RED, curr, WHITE);
			ft_printf("{");
			ft_printf("\tsa: %s%d%s\n", YELLOW, curr->info->sa, WHITE);
			ft_printf("\tsb: %s%d%s\n", YELLOW, curr->info->sb, WHITE);
			ft_printf("\tpa: %s%d%s\n", YELLOW, curr->info->pa, WHITE);
			ft_printf("\tpb: %s%d%s\n", YELLOW, curr->info->pb, WHITE);
			ft_printf("\tra: %s%d%s\n", YELLOW, curr->info->ra, WHITE);
			ft_printf("\trb: %s%d%s\n", YELLOW, curr->info->rb, WHITE);
			ft_printf("\trra: %s%d%s\n", YELLOW, curr->info->rra, WHITE);
			ft_printf("\trrb: %s%d%s\t", YELLOW, curr->info->rrb, WHITE);
			ft_printf("}\n");
		}
		curr = curr->next;
	}
}
