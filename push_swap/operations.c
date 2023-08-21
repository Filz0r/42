/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 12:46:35 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/31 16:17:54 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_list	swap(t_ps_list stack, char current)
{
	int	temp;
	int	i;
	int	*curr_stack;

	int	k = 0;
	i = 0;
	temp = 0;
	curr_stack = NULL; 
	if (current == 'a')
		curr_stack = stack.a_stack;
	else if (current == 'b')
		curr_stack = stack.b_stack;
	ft_printf("before\n"); 
	while (k <= stack.length)
		ft_printf("|%d|\n", curr_stack[k++]);
	temp = curr_stack[0];
	curr_stack[0] = curr_stack[1];
	curr_stack[1] = temp;
	k = 0;
	ft_printf("after\n"); 
	while (k <= stack.length)
		ft_printf("|%d|\n", curr_stack[k++]);
	return (stack);
} 
 
t_ps_list	rotate(t_ps_list stack, char current)
{
	int	length;
	int	i;
	int	*curr_stack;
	int	temp; 

	i = 0;
	temp = MIN_INT;
	length = stack.length;
	if (current == 'a')
		curr_stack = stack.a_stack;
	else if (current == 'b')
		curr_stack = stack.b_stack;
	while (i < length)
	{
		temp = curr_stack[i];

	}
}
/*
void	push(int *origin_stack, int *dest_stack)
{
	int	i;

	i = 0;
	if (!dest_stack || !origin_stack)
	{
		free(dest_stack);
		free(origin_stack);
		errors(1);
	}
	//this doesn't check if the destiny has something inside
	//it assumes that the destiny is empty
	// BAD PRACTICE
	dest_stack[i] = orgin_stack[i];
	while (origin_stack[i] != '\0')
	{
		origin_stack[i] == origin_stack[i + 1];
		i++; 
	}
}



void	reverse_rotate(int *stack)
{

}
 
void	change_both(int *a_stack, int *b_stack, char *operation)
{
	if (operation == "swap")
	{
		swap(a_stack);
		swap(b_stack);
	}
	else if (operation == "rotate")
	{
		rotate(a_stack);
		rotate(b_stack);
	}
	else if (operation == "reverse rotate")
	{
		reverse_rotate(a_stack);
		reverse_rotate(b_stack);
	}
}
*/
