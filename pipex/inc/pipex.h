/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:44:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/15 21:40:48 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <sys/wait.h>

typedef struct s_cmd {
	char	**env;
	char	*path;
	char	*cmd;
	int		fds[2];
	pid_t	pid;
	int		pos;
}				t_cmd;

// todo:delete
typedef struct s_pipe {
	int	infile;
	int	outfile;
}				t_pipe;

// Pipe
void	pipex(t_list *node, int fd);

// commands
t_list	**commands(void);
t_cmd	*new_cmd(t_cmd cmd);
void	commands_init(int size, char **av, char **envp, int outfile);
void	free_cmd(t_list *node);
void	clear_commands(t_list **lst);
void	set_command_fdout(int fd);

// Utils
char	*find_cmd_path(char *path, char *cmd);
void	execute(t_cmd *cmd, int in, int out);
int		dup_closer(int fdin, int fdout);
void	errors(char *msg, char **arr);
char	*get_path(char **envp);

// Debug functions
void	print_cmds(t_list **list, int depth);
void	print_cmd(t_cmd *cmd);

#endif //PIPEX_H
