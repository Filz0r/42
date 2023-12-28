/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 23:15:12 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/27 10:46:12 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Main function of the pipex program
 * @param ac number of arguments
 * @param av array of the arguments
 * @param envp environment variables table
 * @return either 1 or 0 corresponding with the usage.
 * The program can also return 127 if any file is invalid
 */
int	main(int ac, char **av, char **envp)
{
	t_pipe	files;

	if (ac == 5)
	{
		files = open_files(av[1], av[ac - 1]);
		commands_init(ac - 3, av, envp, files);
		pipex(ft_lstget(*commands(), 0), files.infile);
		pid_waiter(files);
		clear_commands(commands());
		return (0);
	}
	ft_printf("Invalid usage\nCorrect usage: ./pipex infile cmd1 cmd2 outfile\n");
	return (1);
}
