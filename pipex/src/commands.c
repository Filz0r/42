/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:46:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/27 14:54:34 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief fake global variable that can be called from wherever.
 * @return returns the reference to a t_list struct
 */
t_list	**commands(void)
{
	static t_list	*cmds;

	return (&cmds);
}

/**
 * @brief allocates the passed in cmd to memory and calls pipe on the .fds field
 * @param cmd a structure of t_cmd that isn't allocated to memory
 * @return a pointer to the allocated structure
 */
t_cmd	*new_cmd(t_cmd cmd)
{
	t_cmd	*res;

	res = malloc(sizeof(t_cmd));
	if (!res)
		return (NULL);
	*res = cmd;
	if (pipe(res->fds) < 0)
		errors("pipes", NULL);
	return (res);
}

/**
 * @brief initializes the global linked list
 * @param size number of elements to be added to the list
 * @param av argv array received from the program arguments
 * @param envp environment variables array got from main function
 * @param outfile file descriptor of the last element of the linked list
 */
void	commands_init(int size, char **av, char **envp, t_pipe fds)
{
	int		i;
	char	*temp_cmd;
	char	**temp;

	i = -1;
	while (++i < size)
	{
		temp = ft_split(av[i + 2], 32);
		temp_cmd = find_cmd_path(get_path(envp), temp[0]);
		ft_lstadd_back(commands(), ft_lstnew(new_cmd((t_cmd){envp, temp_cmd,
					av[i + 2], .fds = {-1, -1}, -69, .files = fds, i})));
		ft_fsplit(temp);
	}
	set_command_fdout(fds.outfile);
}

/**
 * @brief goes trough the global linked list until the last element and sets
 * its fd[1] (stdout) to the file descriptor passed as argument.
 * @param fd file descriptor to be set in the last element
 */
void	set_command_fdout(int fd)
{
	t_list	*temp;
	t_cmd	*cmd;

	temp = *commands();
	while (temp->next != NULL)
		temp = temp->next;
	cmd = ((t_cmd *)temp->content);
	if (!cmd)
		return ;
	close(cmd->fds[1]);
	cmd->fds[1] = fd;
}

/**
 * @brief Closes the file descriptors for the commands inside the
 * child processes.
 * @param pos position where are. This is used to close the infile and outfile
 * before the program calls execve.
 */
void	close_unused_commands(int pos)
{
	t_list	*temp;
	t_cmd	*cmd;

	temp = *commands();
	while (temp)
	{
		cmd = (t_cmd *)temp->content;
		if (!cmd)
			break ;
		if (cmd->pos == pos)
		{
			close(cmd->files.infile);
			close(cmd->files.outfile);
		}
		close(cmd->fds[1]);
		close(cmd->fds[0]);
		temp = temp->next;
	}
}
