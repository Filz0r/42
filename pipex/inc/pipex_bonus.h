/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 20:00:06 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/21 19:17:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <pipex.h>

int		usage(void);
t_pipe	handle_heredoc(char *endfile, const char *eof);
void	fill_heredoc(int fd, const char *eof);

#endif //PIPEX_BONUS_H
