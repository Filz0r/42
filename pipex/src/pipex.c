/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:39:07 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 13:44:30 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * @brief Recursive implementation of an UNIX pipe that goes trough the global
 * linked list and executes every command inside its stack and then goes to the
 * next element of the list until we find  NULL
 * @param node an node of an t_list linked list
 * @param fd a t_pipe struct that contains the file descriptors that we want
 * to set to stdin and stdout respectively
 */
void	pipex(t_list *node, int infile)
{
	t_cmd	*cmd;

	if (!node)
		return ;
	cmd = (t_cmd *)(node->content);
	if (!cmd)
		return ;
	cmd->pid = fork();
	if (cmd->pid == -1)
		errors("Pipex: fork:", NULL);
	else if (cmd->pid == 0)
		execute(cmd, infile, cmd->fds[1]);
	else
		pipex(node->next, cmd->fds[0]);
	close(infile);
	close(cmd->fds[1]);
}

/**
 * @brief duplicates the file descriptors and executes the command
 * @param cmd a pointer to the struct t_cmd that contains the information of
 * the command we want to execute.
 * @param fdin file descriptor that will be our stdin
 * @param fdout file descriptor that will be our stdout
 */
void	execute(t_cmd *cmd, int fdin, int fdout)
{
	char	**temp;
	char	*temp2;

	if (dup_closer(fdin, fdout) >= 0)
	{
		temp = ft_split(cmd->cmd, 32);
		if (cmd->path == NULL)
			temp2 = temp[0];
		else
			temp2 = cmd->path;
		if (execve(temp2, temp, cmd->env) == -1)
			errors(temp2, temp);
	}
}

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
	int	infile;
	int	outfile;

	if (ac == 5)
	{
		infile = open(av[1], O_RDONLY);
		if (infile == -1)
			errors(av[1], NULL);
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (outfile == -1)
			errors(av[4], NULL);
		commands_init(ac - 3, av, envp, outfile);
//		print_cmds(commands(), 0);
		pipex(ft_lstget(*commands(), 0), infile);
		waitpid(-1, NULL, 0);
		clear_commands(commands());
		close(outfile);
		close(infile);
		return (0);
	}
	ft_printf("Invalid usage\nCorrect usage: ./pipex infile cmd1 cmd2 outfile\n");
	return (1);
}
