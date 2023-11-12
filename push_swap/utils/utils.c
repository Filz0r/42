/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:53:25 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/11 22:34:28 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handle_args(int counter, char **values, t_plist **start)
{
	int		i;
	long	num;

	i = 1;
	if (counter == 1)
	{
		values = ft_split(values[1], ' ');
		i = 0;
	}
	while (values[i] != 0 || values[i] != NULL)
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
	if (counter == 1)
		free_words(values);
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
	exit(EXIT_FAILURE);
}
