/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:28 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/14 12:04:44 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Function that frees the memory that was allocated in the eventuality we only
// pass a single argument to the program.
void	free_words(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL || arr[i] != 0)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

// Function created to save line numbers on the handle_args function
// the name explains why this exists.
char	**fuck_norm(const char *str, int *i)
{
	*i = 0;
	return (ft_split(str, ' '));
}
