/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 17:02:46 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 15:19:13 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// This function returns the mean value of the stack
int	get_mean_number(t_plist **stack)
{
	int		res;
	int		i;
	t_plist	*curr;

	res = 0;
	i = 0;
	curr = *stack;
	while (curr)
	{
		res += curr->data;
		i++;
		curr = curr->next;
	}
	return (res / i);
}
