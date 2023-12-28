/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:34:32 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/28 11:42:23 by fparreir         ###   ########.fr       */
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
		if (ft_strncmp(av[1], "here_doc", ft_strlen(av[1])) == 0)
		{
			files = handle_heredoc(av[ac-- - 1], av[2]);
			av = av + 1;
		}
		else
			files = open_files(av[1], av[ac - 1]);
		commands_init(ac - 3, av, envp, files);
		pipex(ft_lstget(*commands(), 0), files.infile);
		pid_waiter(files);
		clear_commands(commands());
		return (0);
	}
	return (usage());
}
