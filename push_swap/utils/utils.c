/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:25 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 12:04:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


// Handles the arguments we pass to the program, it also handles the exceptions
// that are delimited in the Requirements of the project
// This is the function that allows for the program to be able to parse either
// 1 argument eg: ./push_swap "10 42 1 32 5" or multiple arguments
// eg: ./push_swap 10 42 1 32 5
void	handle_args(int counter, char **values, t_plist **start)
{
	int		i;
	long	num;

	i = 1;
	if (counter == 1)
		values = fuck_norm(values[1], &i);
	while (values[i] != 0 || values[i] != NULL)
	{
		if (has_digits(values[i]) == 0)
		{
			if (counter == 1)
				free_words(values);
			errors(start);
		}
		num = ft_atol(values[i++]);
		if (!check_number(num))
			errors(start);
		if (is_num_in_stack(start, (int)num) == 1)
			errors(start);
		add_list_end(start, (int)num);
	}
	if (counter == 1)
		free_words(values);
}

// Checks if a number fits inside an INT variable
int	check_number(long nb)
{
	return (nb >= INT_MIN && nb <= INT_MAX);
}

// Checks if there are any non digit characters in our
// input, basically atoi converted to a true or false function
int	has_digits(const char *str)
{
	int	i;
	int	c;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		c = (int)str[i];
		if (ft_isdigit(c) == 1)
			i++;
		else
		{
			i = 0;
			break ;
		}
	}
	if (i == 0)
		return (0);
	else
		return (1);
}

// Frees the allocated memory of an Linked List
void	free_list(t_plist **start)
{
	t_plist	*curr;
	t_plist	*temp;

	if (*start == NULL)
		return ;
	curr = *start;
	while (curr)
	{
		temp = curr;
		curr = curr->next;
		free(temp->info);
		free(temp);
	}
}

// Frees the list, and prints error on STDERR and exits with the
// correct exit code
void	errors(t_plist **start)
{
	free_list(start);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
