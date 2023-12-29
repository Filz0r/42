/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:31:24 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/29 10:04:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief Error function that also cleans memory
 * @param msg  The value we will pass to perror
 * @param arr  an optional argument that frees memory allocated by ft_split if
 * arr is not NULL.
 * After cleaning the memory and printing the perror message it exits the
 * program with the error code 127 (wrong/invalid file descriptor)
 */
void	errors(char *msg, char **arr, int code)
{
	perror(msg);
	if (arr)
		ft_fsplit(arr);
	if (commands() || *commands())
		clear_commands(commands());
	exit(code);
}

/**
 * @brief Frees the allocated memory of a t_list node containing an
 * t_cmd pointer inside, also closes all file descriptors of this structure,
 * frees the path variable if it was allocated to memory, and deletes the node
 * from the global linked list
 * @param node the node we want to delete from the global linked list
 */
void	free_cmd(t_list *node)
{
	t_cmd	*c;

	c = ((t_cmd *)(node->content));
	if (!c)
		return ;
	if (c->path)
		free(c->path);
	close(c->fds[0]);
	close(c->fds[1]);
	ft_lstdelone(node, free);
}

/**
 * @brief calls free_cmd for every element of the global linked list until it
 * is pointing to NULL (all memory is clean)
 * @param lst reference to the global linked list
 */
void	clear_commands(t_list **lst)
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		free_cmd(*lst);
		*lst = temp;
	}
	*lst = NULL;
}
