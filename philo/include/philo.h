/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 16:59:41 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:39:54 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <string.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_times {
	unsigned long	start_time;
	unsigned long	last_eaten;
	unsigned long	time_to_sleep;
	unsigned long	time_to_eat;
	unsigned long	time_to_die;
}		t_times;

typedef struct s_philo {
	int				id;
	int				num_philos;
	int				printed;
	bool			*dead;
	void			*program;
	t_times			timestamps;
	pthread_t		thread;
	unsigned int	times_eaten;
	unsigned int	times_to_eat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}				t_philo;

typedef struct s_program {
	int				num_of_philo;
	bool			dead;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
}			t_program;

//initialization
t_program		*memory_init(char **av);
pthread_mutex_t	*forks_init(int size);
t_philo			*philos_init(char **av, t_program *program,
					unsigned long start);
void			add_forks_to_philo(pthread_mutex_t *forks, int pos, int size,
					t_philo *philo);

//Philosopher and Threads function
void			threading(t_program *program);
void			*loop(void *ptr);
void			philo_think(t_philo *philo);
void			philo_eat(t_philo *philo);
void			philo_eat_even(t_philo *philo);
void			philo_eat_odd(t_philo *philo);
void			philo_sleep(t_philo *philo);
int				is_everyone_ok(t_philo *philo);
int				am_i_alive(t_philo *philo);
int				am_i_full(t_philo *philo);

// utils
void			ft_usleep(unsigned long sleep_time);
unsigned long	get_current_time(void);
long			char_to_uint(const char *str);
void			put_thread_msg(char *str, t_philo *philosopher);

#endif //PHILO_H
