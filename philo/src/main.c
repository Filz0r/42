/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:30:00 by fparreir          #+#    #+#             */
/*   Updated: 2024/01/10 11:23:17 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <errors.h>

int	main(int ac, char **av)
{
	t_program	*program;

	if (ac != 5 && ac != 6)
		return (usage());
	if (check_usage(av))
		return (1);
	program = memory_init(av);
	if (program != NULL)
	{
		threading(program);
		destroy(NULL, program);
	}
	return (0);
}
