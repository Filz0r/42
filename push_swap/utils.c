/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 14:52:29 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/29 16:43:50 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_ps_list	handle_args(int counter, char **values)
{
	int			k;
	int			i;
	int			*temp;
	int			*temp2;
	int			arg; 
	t_ps_list	stack;

	k = 1;
	i = 0;
	arg = 0;
	temp = malloc(sizeof(int) * counter);
	temp2 = malloc(sizeof(int) * counter);
	if (!temp || !temp2)
		errors(2);
	while (counter--)
	{
		arg = ft_atoi(values[k]);
		if (arg != 0)
		{
			temp[i] = arg;
			i++;
		}
		else
			errors(1);
		k++; 
	}
	stack.a_stack = temp;
	i = 0; 
	while (i < k - 1)
		temp2[i++] = 0;
	stack.b_stack = temp2;
	stack.length = k - 2; 
	return (stack); 
}
 
void	errors(int err_type)
{
	if (err_type == 0)
	{ 
		ft_printf("\033[1;31mERROR:\033[0m insuficient number of arguments!\n");
		exit(2);
	}
	else if (err_type == 1)
	{
		ft_printf("\033[1;31mERROR:\033[0m One of your arguments could not be converted into a int!\n");
		exit(2);
	}
	else if (err_type == 2)
	{
		ft_printf("\033[1;31mERROR:\033[0m Error allocating memory for the stack!\n");
		exit(2);
	}
}
