/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:33:00 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:24:31 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errors.h>
#include <philo.h>

void	put_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(STDERR_FILENO, &str[i], 1);
	write(STDERR_FILENO, "\n", 1);
}

int	check_usage(char **av)
{
	if (char_to_uint(av[1]) <= 0)
		return (put_error("Cannot have less than 1 philo -_-\n"
				"Or don't try to give non numbers or 0 -_-"), 1);
	else if (char_to_uint(av[2]) <= 0)
		return (put_error("Cannot die in negative time -_-\n"
				"Or don't try to give non numbers or 0 -_-"), 1);
	else if (char_to_uint(av[3]) <= 0)
		return (put_error("Cannot eat in negative time -_-\n"
				"Or don't try to give non numbers or 0 -_-"), 1);
	else if (char_to_uint(av[4]) <= 0)
		return (put_error("Cannot sleep negative time -_-\n"
				"Or don't try to give non numbers or 0 -_-"), 1);
	else if (av[5] && char_to_uint(av[5]) <= 0)
		return (put_error("Cannot eat negative times -_-\n"
				"Or don't try to give non numbers or 0 -_-"), 1);
	return (0);
}

int	usage(void)
{
	put_error("Incorrect usage! To run this program you need to use the"
		" following syntax: \n" "./philo <number of philosophers>"
		" <time to die> <time to eat> <time to sleep> "
		"[times to eat - optional argument]");
	return (1);
}

void	destroy(char *str, void *ptr)
{
	int			i;
	t_program	*prog;

	if (str)
		put_error(str);
	prog = (t_program *)ptr;
	if (!prog)
		return ;
	i = -1;
	while (++i < prog->num_of_philo)
		pthread_mutex_destroy(&prog->forks[i]);
	pthread_mutex_destroy(&prog->write_lock);
	free(prog->forks);
	free(prog->philos);
	free(prog);
}
