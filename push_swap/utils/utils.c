/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:25 by fparreir          #+#    #+#             */
/*   Updated: 2023/08/25 16:20:40 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*handle_args(int counter, char **values, t_plist **start)
{
	int		i;
	int		k;
	int		*array;
	long	num;

	i = 1;
	while (i <= counter)
	{
		if (has_digits(values[i]) == 0)
			errors();
		num = ft_atol(values[i++]);
		if (!check_number(num))
			errors();
		if (is_num_in_stack(start, (int)num) == 1)
			errors();
		add_list_end(start, (int)num);
	}
	i = 0;
	k = 1;
	array = malloc(sizeof(int) * counter);
	while (k <= (counter))
	{
		array[i++] = ft_atoi(values[k++]);
	}
	return (array);
}

int	check_number(long nb)
{
	return (nb >= INT_MIN && nb <= INT_MAX);
}

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

void	errors(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(2);
}
