/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:27:33 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/25 14:53:42 by fparreir         ###   ########.fr       */
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
	ft_printf("\n{\n\tparent:%s%x%s,\n" \
					"\tbf: %s%x%s\n" \
					"\tstack_size: %s%c%s,\n" \
					"\ttotal_size: %s%d%s\n}\n", \
			GREEN, curr->info->parent, WHITE, \
			GREEN, curr->info->bf, WHITE, \
			GREEN, curr->info->stack_size, WHITE, \
			GREEN, curr->info->total_size, WHITE);
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
