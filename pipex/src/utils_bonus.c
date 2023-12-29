/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 00:07:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/29 11:58:16 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

/**
 * @brief Prints an usage error message before returning the exit code
 * for improper usage.
 * @return Always returns 1.
 */
int	usage(void)
{
	ft_putendl_fd("Invalid usage\n"
		"Correct usage: ./pipex infile cmd1 ... cmdn outfile\n", STDERR_FILENO);
	ft_putendl_fd("An alternative is to pass here_doc and a"
		" delimiter as the first and second arguments"
		"of the program to simulate the behaviour of"
		"an heredoc functionality.", STDERR_FILENO);
	return (1);
}

/**
 * @brief Opens the file given by the outfile path, and simulates and heredoc
 * behaviour by piping the stdin and stdout of the process and filling it with
 * the text the user provides to the process stdin and then writing it to stdout
 * @param outfile path to the file we want to output to
 * @param eof delimiter used to get out of heredoc
 * @return returns a t_pipe struct that contains the read end of the
 * pipe we created so that the following processes can read from it
 * and also contains the outfile.
 *
 * NOTE: a t_pipe struct contains the file descriptors that the commands
 * need to execute, fuck norm, long live stack allocated memory.
 */
t_pipe	handle_heredoc(char *outfile, const char *eof)
{
	int	out;
	int	in;
	int	pipes[2];

	if (pipe(pipes) < 0)
		errors("Pipex: pipe error:", NULL, 127);
	in = pipes[0];
	fill_heredoc(pipes[1], eof);
	close(pipes[1]);
	out = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (out == -1)
		errors(outfile, NULL, 127);
	return ((t_pipe){in, out});
}

/**
 * @brief Opens an infinite loop used to fill the write end of the pipe
 * handle_heredoc creates, this look can be exited by pressing CTRL + D
 * or by giving a line containing the EOF string to the loop.
 * @param fd File descriptor of the write end of the pipe
 * @param eof string delimiter used to exit heredoc
 */
void	fill_heredoc(int fd, const char *eof)
{
	char	*line;

	while (1)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!line)
		{
			ft_putendl_fd("pipex: Warning: "
				"heredoc was closed manually", STDERR_FILENO);
			break ;
		}
		if (line != NULL && ft_strncmp(line, eof, ft_strlen(eof)) == 0)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
}
