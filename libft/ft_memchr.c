/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:00:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/17 16:22:10 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t length)
{
	unsigned char	*string;
	unsigned char	value;

	string = (unsigned char *)str;
	value = (unsigned char)c;
	while (length--)
	{
		if (*string == value)
			return ((unsigned char *)string);
		string++;
	}
	return (0);
}
