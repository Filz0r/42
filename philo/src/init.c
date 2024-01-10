/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:34:38 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:22:55 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <errors.h>

t_program	*memory_init(char **av)
{
	t_program	*res;
	int			size;

	size = (int)char_to_uint(av[1]);
	res = malloc(sizeof(t_program));
	if (!res)
		return (NULL);
	memset(res, 0, sizeof(t_program));
	res->dead = false;
	res->num_of_philo = size;
	pthread_mutex_init(&res->write_lock, NULL);
	res->forks = forks_init(size);
	if (!res->forks)
		return (destroy("Memory initialization error", res), NULL);
	res->philos = philos_init(av, res, get_current_time());
	if (!res->philos)
		return (destroy("Memory initialization error", res), NULL);
	return (res);
}

pthread_mutex_t	*forks_init(int size)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = malloc(sizeof(pthread_mutex_t) * size);
	if (!forks)
		return (NULL);
	memset(forks, 0, (sizeof(pthread_mutex_t) * size));
	while (++i < size)
		pthread_mutex_init(&forks[i], NULL);
	return (forks);
}

t_philo	*philos_init(char **av, t_program *program, unsigned long start)
{
	t_philo	*res;
	int		i;

	res = malloc(sizeof(t_philo) * program->num_of_philo);
	if (!res)
		return (NULL);
	memset(res, 0, (sizeof(t_philo) * program->num_of_philo));
	i = -1;
	while (++i < program->num_of_philo)
	{
		res[i].num_philos = program->num_of_philo;
		res[i].dead = &program->dead;
		res[i].program = (void *)program;
		res[i].timestamps = (t_times){start, start, char_to_uint(av[4]),
			char_to_uint(av[3]), char_to_uint(av[2])};
		if (av[5])
			res[i].times_to_eat = char_to_uint(av[5]);
		else
			res[i].times_to_eat = -1;
		add_forks_to_philo(program->forks, i, program->num_of_philo, &res[i]);
	}
	return (res);
}

void	add_forks_to_philo(pthread_mutex_t *forks, int pos, int size,
			t_philo *philo)
{
	philo->l_fork = &forks[pos];
	if (pos == (size - 1))
		philo->r_fork = &forks[0];
	else
		philo->r_fork = &forks[pos + 1];
	philo->printed = 0;
	philo->times_eaten = 0;
	philo->id = pos + 1;
}
