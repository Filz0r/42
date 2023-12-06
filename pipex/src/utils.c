/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/06 17:56:05 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*find_cmd_path(char *path, char *cmd)
{
	int		i;
	char	*temp;
	char	**paths;
	char	*temp2;


	paths = ft_split(path, ':');
	i = 0;
	while (paths[i] != 0)
	{
		temp2 = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp2, cmd);
		if (access(temp, F_OK) == 0)
			return (temp);
		free(temp2);
		free(temp);
		i++;
	}
	ft_fsplit(paths);
	return (NULL);
}

void	exec(char *cmd, char **envp)
{
	char	*path;
	char	**command;
	int		i;

	command = ft_split(cmd, 32);
	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			path = envp[i] + 5;
		i++;
	}
	path = find_cmd_path(path, command[0]);
	if (path != NULL)
		execve(path, command, envp);
	else
	{
		perror(command[0]);
		ft_fsplit(command);
	}
}

void	errors(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
