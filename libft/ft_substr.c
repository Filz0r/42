/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:30:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/20 16:47:21 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_ret_empty_str(void)
{
	char	*buffer;

	buffer = malloc(1);
	if (buffer)
		*buffer = 0;
	return (buffer);
}

char	*ft_substr(char const *str, unsigned int start, size_t length)
{
	char	*buffer;
	size_t	i;
	size_t	k;
	size_t	len;

	i = 0;
	k = 0;
	len = ft_strlen(str);
	if (start >= len || length == 0)
		return (ft_ret_empty_str());
	if (len - start >= length)
		len = length;
	else
		len = len - start;
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (str[i])
	{
		if (i >= start && k < length)
			buffer[k++] = str[i];
		i++;
	}
	buffer[k] = 0;
	return (buffer);
}
