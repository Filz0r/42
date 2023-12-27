/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:07:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/21 00:13:46 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	usage(void)
{
	ft_putendl_fd("Invalid usage\n"
		"Correct usage: ./pipex infile cmd1 ... cmdn outfile\n", 2);
	return (1);
}

t_pipe	open_files(char *infile, char *outfile)
{
	int	in;
	int	out;

	in = open(infile, O_RDONLY);
	if (in == -1)
		errors(infile, NULL);
	out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (out == -1)
		errors(outfile, NULL);
	return ((t_pipe){in, out});
}
