/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:00:38 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/21 17:23:54 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	bubble_sort(int *arr, int size)
{
	int	k;
	int	i;
	int	swapped;

	i = 0;
	while (i <= (size - 1))
	{
		swapped = 0;
		k = 0;
		while (k <= (size - 2))
		{
			if (arr[k] > arr[k + 1])
			{
				swap(&arr[k], &arr[k + 1]);
				swapped = 1;
			}
			k++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}

int	get_array_index(int *arr, int size, int nb)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}
