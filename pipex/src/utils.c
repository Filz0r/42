/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:54:19 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 12:02:53 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**
 * @brief Finds the path of an command on the environment
 * @param path The path of the environment (everything after PATH=)
 * @param cmd The name of the command we are looking for
 * @return If the cmd or the path are NULL or cannot be found the
 * function returns NULL otherwise returns a pointer to the path of
 * the command with memory allocated to it.
 */
char	*find_cmd_path(char *path, char *cmd)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	**paths;

	if (!path || (cmd == NULL || *cmd == '\0'))
		return (NULL);
	paths = ft_split(path, ':');
	i = -1;
	while (paths[++i] != 0)
	{
		temp2 = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp2, cmd);
		if (access(temp, F_OK) == 0)
			return (ft_fsplit(paths), free(temp2), temp);
		free(temp2);
		free(temp);
	}
	ft_fsplit(paths);
	return (NULL);
}

/**
 * @brief finds the PATH environment variable and returns it ignoring PATH=
 * @param envp The array of environment variables
 * @return if the environment is empty or the PATH variable cannot be fount it
 * returns NULL otherwise it will return a pointer to everything after PATH=
 * inside the envp array.
 */
char	*get_path(char **envp)
{
	int		i;

	i = 0;
	if (!envp || *envp == NULL)
		return (NULL);
	while (envp[i] != 0)
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != NULL)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
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
	if (fdin == STDIN_FILENO)
		close(fdin);
	return (1);
}
