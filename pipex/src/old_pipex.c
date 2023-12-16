/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:42:26 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/08 19:48:00 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

// TODO: DELETE ME
void	run_child(int *fds, char **av, char **envp); // del
void	run_parent(int *fds, char **av, char **envp); // del
void	p_waiter(pid_t child1, int *fds, char **av, char **envp); // del
void	executor(char *cmd, char **envp);

void	run_parent(int *fds, char **av, char **envp)
{
	int	outfile;

	close(fds[1]);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		errors(av[4], NULL);
	dup2(fds[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	executor(av[3], envp);
	errors("pipex", NULL);
}

void	run_child(int *fds, char **av, char **envp)
{
	int	infile;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		errors(av[1], NULL);
	close(fds[0]);
	dup2(infile, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	executor(av[2], envp);
	errors("pipex", NULL);
}

void	p_waiter(pid_t child1, int *fds, char **av, char **envp)
{
	pid_t	child2;

	close(fds[1]);
	child2 = fork();
	if (child2 == -1)
		errors("Fork", NULL);
	else if (child2 == 0)
		run_parent(fds, av, envp);
	close(fds[0]);
	waitpid(child1, NULL, 0);
	waitpid(child2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	int			fds[2];
	pid_t		child1;

	if (ac == 5)
	{
		if (pipe(fds) == -1)
			errors("Pipe", NULL);
		child1 = fork();
		if (child1 == -1)
			errors("Fork", NULL);
		else if (child1 == 0)
			run_child(fds, av, envp);
		else
			p_waiter(child1, fds, av, envp);
		return (0);
	}
	ft_printf("Invalid usage\nCorrect usage: ./pipex infile cmd1 cmd2 outfile\n");
	return (1);
}

// TODO: refactor
void	executor(char *cmd, char **envp)
{
	char	*cmd_to_run;
	char	*cmd_path;
	char	**command;
	char	*path;


	command = ft_split(cmd, 32);
	path = get_path(envp);
	if (path == NULL)
		cmd_path = find_cmd_path(path, command[0]);
	else
		cmd_path = NULL;
	if (cmd_path == NULL)
		cmd_to_run = command[0];
	else
		cmd_to_run = cmd_path;
	if (execve(cmd_to_run, command, envp) == -1)
		errors(cmd_to_run, command);
}