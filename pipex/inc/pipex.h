/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:44:10 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/21 21:48:07 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <sys/wait.h>

typedef struct s_pipe {
	int	infile;
	int	outfile;
}				t_pipe;

typedef struct s_cmd {
	char	**env;
	char	*path;
	char	*cmd;
	int		fds[2];
	pid_t	pid;
	t_pipe	files;
	int		pos;
}				t_cmd;

// Pipe
void	pipex(t_list *node, int fd);
void	execute(t_cmd *cmd, int in, int out);
int		dup_closer(int fdin, int fdout);
void	pid_waiter(t_pipe files);
t_pipe	open_files(char *infile, char *outfile);

// commands
t_list	**commands(void);
t_cmd	*new_cmd(t_cmd cmd);
void	commands_init(int size, char **av, char **envp, t_pipe files);
void	free_cmd(t_list *node);
void	clear_commands(t_list **lst);
void	set_command_fdout(int fd);
void	close_unused_commands(int pos);

// Utils
char	*find_cmd_path(char *path, char *cmd);
void	errors(char *msg, char **arr);
char	*get_path(char **envp);

// Debug functions
void	print_cmds(t_list **list, int depth);
void	print_cmd(t_cmd *cmd);

#endif //PIPEX_H
