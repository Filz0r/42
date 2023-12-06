/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:44:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/06 17:55:37 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"

void	run_child(int *fds, char **av, char **envp);
void	run_parent(int *fds, char **av, char **envp);
char	*find_cmd_path(char *path, char *cmd);
void	exec(char *cmd, char **envp);
void	errors(char *msg);

#endif //PIPEX_H
