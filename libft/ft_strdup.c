/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:29:03 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/17 16:21:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
