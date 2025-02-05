/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 15:52:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/22 01:51:23 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	print_cmd(t_cmd *cmd)
{
	ft_printf("cmd: {\n cmd: %s,\n pos: %d,\n pid: %d,\n"
		" path: %s,\n fdsin: %d,\n fdsout: %d,\n "
		"infile: %d,\n outfile: %d\n }\n",
		cmd->cmd,
		cmd->pos,
		cmd->pid,
		cmd->path,
		cmd->fds[0],
		cmd->fds[1],
		cmd->files.infile,
		cmd->files.outfile);
}

void	print_cmds(t_list **list, int depth)
{
	t_list	*temp;
	t_cmd	*c;

	if (!list || !(*list))
		return ;
	temp = *list;
	while (temp != NULL)
	{
		c = ((t_cmd *)(temp->content));
		print_cmd(c);
		if (depth && c->pid != 0)
			waitpid(-1, &c->fds[0], 0);
		temp = temp->next;
	}
}
