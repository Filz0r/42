/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:32 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/20 17:53:02 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

/**
 * @brief Main function of the bonus pipex program
 * @param ac number of arguments
 * @param av array of the arguments
 * @param envp environment variables table
 * @return either 1 or 0 corresponding with the usage.
 * The program can also return 127 if any file is invalid
 */
int	main(int ac, char **av, char **envp)
{
	t_pipe	files;

	if (ac >= 5)
	{
		files = open_files(av[1], av[ac - 2]);
		commands_init(ac - 3, av, envp, files);
		pipex(ft_lstget(*commands(), 0), files.infile);
		pid_waiter();
		close(files.outfile);
		close(files.infile);
		clear_commands(commands());
		return (0);
	}
	return (usage());
}
