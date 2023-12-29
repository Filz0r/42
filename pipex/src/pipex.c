/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:39:07 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/29 10:01:13 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

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
		errors("Pipex: fork:", NULL, 12);
	else if (cmd->pid == 0)
		execute(cmd, infile, cmd->fds[1]);
	else
	{
		close(infile);
		close(cmd->fds[1]);
		pipex(node->next, cmd->fds[0]);
	}
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

	if (dup_closer(dup(fdin), dup(fdout)) >= 0)
	{
		temp = ft_split(cmd->cmd, 32);
		if (cmd->path == NULL)
		{
			if (!(*temp))
				temp2 = cmd->cmd;
			else
				temp2 = temp[0];
		}
		else
			temp2 = cmd->path;
		close_unused_commands(cmd->pos);
		if (execve(temp2, temp, cmd->env) == -1)
			return (errors(temp2, temp, 13));
	}
}

/**
 * @brief duplicates and closes the fdin and fdout to stdin and stdout
 * respectively
 * @param fdin file descriptor we want to make stdin
 * @param fdout file descriptor we want to make stdout
 * @return either -1 if dup2 fails or 1 if everything works.
 */
int	dup_closer(int fdin, int fdout)
{
	if (dup2(fdout, STDOUT_FILENO) < 0)
		return (-1);
	close(fdout);
	if (dup2(fdin, STDIN_FILENO) < 0)
		return (-1);
	close(fdin);
	return (1);
}

/**
 * @brief Waits for all child processes with an loop, rtfm on the returns of
 * waitpid. Also closes the in and out files
 * @param files t_pipe struct that contains the file descriptors of the in and
 * out files that need to be closed.
 *
 * Reasoning for this is like I wanted my code to be smaller on the main
 * function so yeah.
 */
void	pid_waiter(t_pipe files)
{
	while (waitpid(-1, NULL, 0) > 0)
		;
	close(files.infile);
	close(files.outfile);
}
