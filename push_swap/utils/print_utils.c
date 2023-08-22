/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:27:33 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/22 10:52:19 by fparreir         ###   ########.fr       */
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
		ft_printf("[ value: %s%d%s, pos: %s%d%s, next: %s%p%s ]", \
			YELLOW, curr->data, WHITE, \
			GREEN, curr->pos, WHITE, \
			CYAN, curr->next, WHITE);
		if (curr->next != NULL)
			ft_printf("\n");
		curr = curr->next;
	}
	ft_printf("\n%s", WHITE);
}
