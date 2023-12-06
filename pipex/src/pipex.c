/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:42:26 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/06 17:50:44 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	run_parent(int *fds, char **av, char **envp)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY);
	dup2(fds[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fds[1]);
	exec(av[3], envp);
}

void	run_child(int *fds, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	dup2(fds[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fds[0]);
	exec(av[2], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fds[2];
	pid_t	pid;

	if (ac >= 2 && ac - 1 == 5)
	{
		if (access(av[1], F_OK) == -1)
		{
			perror(av[1]);
			return (1);
		}
		if (pipe(fds) == -1)
			errors("Pipe");
		pid = fork();
		if (pid == -1)
			errors("Fork");
		if (pid == 0)
			run_child(fds, av, envp);
		else
			run_parent(fds, av, envp);
	}
	else
		return (1);
	return (0);
}
