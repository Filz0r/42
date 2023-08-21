/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:39:50 by fparreir          #+#    #+#             */
/*   Updated: 2023/07/06 21:08:00 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	sort_small(int counter, t_ps_list stack)
{
	int	i;
	int	k;
	int *temp;
	int	length;

	i = 0;
	k = 0;
	temp = stack.a_stack;
	counter = 0;
	length = stack.length;
//	printf("|%d|\n", stack.a_stack[i]); 
//	printf("|%d|\n", stack.a_stack[i + 1]); 
//	printf("|%d|\n", stack.a_stack[stack.length]); 
	// THIS IS MEGA BROKEN 
	while (is_sorted(stack) == 0 && (i <= length && i + 1 <= length))
	{
		if (length <= 3)
		{
			if (temp[i] > temp[i + 1] && temp[length - 1] < temp[i])
			{
				ft_printf("sa\n");
				ft_printf("i->|%d|\n", i);
				stack = swap(stack, 'a');
			}
			else if(temp[i] > temp[i + 1] && temp[length - 1] < temp[i])
			{
				ft_printf("ra\n");
				stack = rotate(stack, 'a'); 
				ft_printf("ra\n");
				stack = rotate(stack, 'a'); 
			}
		}
		i++;
	}
	while (k <= stack.length)
	{
		ft_printf("|%d|\n", stack.a_stack[k]);
		k++;
	}
	free(stack.a_stack);
	free(stack.b_stack);
	exit(0);
/*	if (temp[i] > temp[i + 1] && temp[i] < temp[stack.length])
	{
		ft_printf("sa\n");
		stack = swap(stack, 'a');
	}
	else if (temp[stack.length - 1] > temp[stack.length])
	{
		ft_printf("")
	}
	else if (temp[i] < temp[i + 1] && temp[i] < temp[stack.length])
	{

	}
	while (counter--)
	{
		ft_printf("|%d|\n", temp_a[i]);
		
		i++;
	}
*/ 
}

void	sort_big(int counter, t_ps_list stack)
{
	counter = 0;
	stack.length = 69;
	ft_printf("I still do nothing!\n");
	exit(1);
}

int	is_sorted(t_ps_list stack)
{
	int	result;
	int	i;

	i = 0;
	result = 0;
	while (i < stack.length - 1 && stack.a_stack[i])
	{
		if (stack.a_stack[i] > stack.a_stack[i + 1])
		{
			result = 1;
			break ;
		}
		i++;
	}
	return (result);
}
