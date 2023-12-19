/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:14:20 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/16 21:28:45 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

// THIS CODE IS ONLY USED FOR DEBUGGING REASONS
/*
static unsigned long	g_total_frames = 0;

void	print_time_status(t_game *g, struct timespec *last_tick)
{
	static struct timespec	last_print;
	struct timespec			current;
	double					elapsed_time;
	double					fps;

	(void)last_tick;
	clock_gettime(CLOCK_MONOTONIC, &current);
	elapsed_time = (current.tv_sec - last_print.tv_sec)
		+ (current.tv_nsec - last_print.tv_nsec) / 1.0e9;
	if (elapsed_time >= 1.0)
	{
		g_total_frames = g->frames;
		fps = g_total_frames / elapsed_time;
		printf("FPS: %.2f Frames: %lu Ticks: %lu FPT: %.2f\n",
			fps, g_total_frames, g->tick, (double)g_total_frames / g->tick);
		last_print = current;
	}
	else
		g_total_frames++;
	*last_tick = current;
}
*/
