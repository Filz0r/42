/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:34:28 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/11 22:34:28 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

char	**fuck_norm(const char *str, int *i)
{
	*i = 0;
	return (ft_split(str, ' '));
}
