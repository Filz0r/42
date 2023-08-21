/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:01:47 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/15 12:56:55 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

void	*ft_memset(void *str, int c, size_t length)
{
	unsigned char	*string;

	string = (unsigned char *)str;
	while (length--)
		*string++ = (unsigned char)c;
	return (str);
}
