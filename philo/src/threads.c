/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:54:57 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:26:11 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <errors.h>

int	am_i_alive(t_philo *philo)
{
	t_program	*prog;

	prog = (t_program *)philo->program;
	if (!prog)
		return (0);
	pthread_mutex_lock(&prog->write_lock);
	if (*philo->dead == true)
		return (pthread_mutex_unlock(&prog->write_lock), 0);
	if ((get_current_time() - philo->timestamps.last_eaten)
		>= philo->timestamps.time_to_die)
	{
		*philo->dead = true;
		philo->printed = 1;
		pthread_mutex_unlock(&prog->write_lock);
		put_thread_msg("died", philo);
		return (0);
	}
	pthread_mutex_unlock(&prog->write_lock);
	return (1);
}

int	am_i_full(t_philo *philo)
{
	if (philo->times_eaten == philo->times_to_eat)
		return (1);
	return (0);
}

int	is_everyone_ok(t_philo *philo)
{
	t_program	*prog;

	prog = (t_program *)philo->program;
	if (!prog)
		return (0);
	pthread_mutex_lock(&prog->write_lock);
	if (prog->dead)
		return (pthread_mutex_unlock(&prog->write_lock), 0);
	pthread_mutex_unlock(&prog->write_lock);
	return (1);
}

void	*loop(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (!philo)
		return (NULL);
	if (philo->id % 2 == 0)
		ft_usleep(10);
	while (is_everyone_ok(philo))
	{
		philo_think(philo);
		philo_eat(philo);
		if (am_i_full(philo))
			break ;
		philo_sleep(philo);
	}
	return (ptr);
}

void	threading(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->num_of_philo)
		if (pthread_create(&program->philos[i].thread, NULL, &loop,
				&program->philos[i]) != 0)
			return (destroy("Error creating threads for dumb philos", program));
	i = -1;
	while (++i < program->num_of_philo)
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (destroy("Error joining threads of dumb philos", program));
}
