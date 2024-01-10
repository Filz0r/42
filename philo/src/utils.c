/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:50:18 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:24:46 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <errors.h>

static int	ft_check_sign(const char *str, int *pos)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i + 1] == 45 || str[i + 1] == 43)
			return (0);
		if (str[i] == 45 || str[i] == 43)
			sign = -1;
	}
	*pos = i;
	return (sign);
}

long	char_to_uint(const char *str)
{
	int				sign;
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	sign = ft_check_sign(str, &i);
	if (sign <= 0)
		return (-1);
	else
	{
		while (str[i] && (str[i] >= 48 && str[i] <= 57))
		{
			res *= 10;
			res += str[i] - 48;
			i++;
			if (res > UINT_MAX)
				return (-1);
		}
		return ((long)res);
	}
}

unsigned long	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		put_error("Error getting time");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(unsigned long sleep_time)
{
	unsigned long	start;

	start = get_current_time();
	while (get_current_time() - start < sleep_time)
		usleep(500);
}

void	put_thread_msg(char *str, t_philo *philo)
{
	unsigned long	time;
	t_program		*prog;

	prog = (t_program *) philo->program;
	if (!prog)
		return ;
	if (pthread_mutex_lock(&prog->write_lock) == 0)
	{
		if (*philo->dead && philo->printed != 1)
			return ((void)pthread_mutex_unlock(&prog->write_lock));
		time = get_current_time() - philo->timestamps.start_time;
		printf("%lu %d %s\n", time, philo->id, str);
		philo->printed = 0;
		pthread_mutex_unlock(&prog->write_lock);
	}
}
