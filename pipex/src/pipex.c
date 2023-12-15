/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:39:07 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/15 17:57:23 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex(t_list *node, t_pipe fd, int count)
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
		execute(cmd, fd.infile, cmd->fds[1]);
	close(fd.infile);
	close(fd.outfile);
	pipex(node->next, (t_pipe){cmd->fds[0], cmd->fds[1]}, ++count);
}

void	execute(t_cmd *cmd, int fdin, int fdout)
{
	char	**temp;
	char	*temp2;

	if (dup_closer(fdin, fdout) >= 0)
	{
		if (cmd->cmd != NULL && cmd->cmd[0] != '\0')
		{
			temp = ft_split(cmd->cmd, 32);
			if (cmd->path == NULL)
				temp2 = cmd->cmd;
			else
				temp2 = cmd->path;
			if (execve(temp2, temp, cmd->env) == -1)
				errors(temp2, temp);
		}
	}
}

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
		pipex(ft_lstget(*commands(), 0), (t_pipe){infile, outfile}, 0);
		waitpid(-1, &outfile, 0);
		close(outfile);
		clear_commands(commands());
		return (0);
	}
	ft_printf("Invalid usage\nCorrect usage: ./pipex infile cmd1 cmd2 outfile\n");
	return (1);
}
