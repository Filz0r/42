/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:20:41 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/23 14:19:05 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int	main(void)
{
	char	*line;
	int		file;

	file = open("./test_long.txt", O_RDONLY);
	while ((line = get_next_line(file)) != NULL)
	{
		ft_printf("LINE ->|%s|\n", line);
		free(line);
	}
	close(file);
	ft_putstr_fd("Goodbye world\n", 1); 
	return (0);
}
