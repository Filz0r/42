/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 14:46:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/15 17:58:30 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

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
	pipe(res->fds);
	return (res);
}

/**
 * @brief
 * @param size
 * @param av
 * @param envp
 * @param outfile
 */
void	commands_init(int size, char **av, char **envp, int outfile)
{
	int		i;
	char	*temp_cmd;
	char	**temp;

	i = -1;
	while (++i < size)
	{
		if (av[i + 2] == NULL || *av[i + 2] == '\0')
			temp_cmd = "/dev/null";
		else
		{
			temp = ft_split(av[i + 2], 32);
			temp_cmd = find_cmd_path(get_path(envp), temp[0]);
		}
		ft_lstadd_back(commands(), ft_lstnew(new_cmd((t_cmd){envp, temp_cmd,
					av[i + 2], .fds = {-1, -1}, -69, i})));
		if (temp_cmd != NULL)
			if (ft_strncmp(temp_cmd, "/dev/null", 9) != 0)
				ft_fsplit(temp);
	}
	set_command_fdout(outfile);
}

/**
 * @brief
 * @param fd
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
	cmd->fds[1] = fd;
}
