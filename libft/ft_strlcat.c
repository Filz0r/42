/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:35:54 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/15 14:03:35 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	d;
	size_t	result;

	if (size == 0)
		return (ft_strlen(src));
	d = ft_strlen((const char *)dest);
	result = d + ft_strlen(src);
	if (size <= d)
		return (size + ft_strlen(src));
	while (*src && (d < size - 1))
		dest[d++] = *src++;
	if (d < size)
		dest[d] = 0;
	return (result);
}
