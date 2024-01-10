/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:08:55 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:36:31 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	philo_think(t_philo *philo)
{
	if (am_i_alive(philo) == 1)
		put_thread_msg("is thinking", philo);
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
		philo_eat_even(philo);
	else
		philo_eat_odd(philo);
}

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	put_thread_msg("has taken a fork", philo);
	if (philo->num_philos == 1 && *philo->dead == false)
	{
		ft_usleep(philo->timestamps.time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	if (am_i_alive(philo) == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		{
			put_thread_msg("has taken a fork", philo);
			philo->timestamps.last_eaten = get_current_time();
			philo->times_eaten++;
			put_thread_msg("is eating", philo);
			ft_usleep(philo->timestamps.time_to_eat);
			pthread_mutex_unlock(philo->l_fork);
		}
	}
	pthread_mutex_unlock(philo->r_fork);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	put_thread_msg("has taken a fork", philo);
	if (philo->num_philos == 1 && *philo->dead == false)
	{
		ft_usleep(philo->timestamps.time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	if (am_i_alive(philo) == 1)
	{
		pthread_mutex_lock(philo->r_fork);
		{
			put_thread_msg("has taken a fork", philo);
			philo->timestamps.last_eaten = get_current_time();
			philo->times_eaten++;
			put_thread_msg("is eating", philo);
			ft_usleep(philo->timestamps.time_to_eat);
			pthread_mutex_unlock(philo->r_fork);
		}
	}
	pthread_mutex_unlock(philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	if (am_i_alive(philo) == 1)
	{
		put_thread_msg("is sleeping", philo);
		ft_usleep(philo->timestamps.time_to_sleep);
	}
}
