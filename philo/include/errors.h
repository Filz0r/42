/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 16:28:13 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/04 16:53:45 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

# include <unistd.h>

int		usage(void);
int		check_usage(char **av);
void	put_error(char *str);
void	size_err(void);
void	destroy(char *str, void *ptr);

#endif //ERRORS_H