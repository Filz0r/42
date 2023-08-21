/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:57:02 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/18 10:06:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (little[i])
		i++;
	if (i == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		while (little[k] && big[i + k] == little[k] && (i + k) < len)
			k++;
		if (little[k] == 0)
			return ((char *)&big[i]);
		i++;
		k = 0;
	}
	if (little[k] == 0)
		return ((char *)big);
	return (NULL);
}
