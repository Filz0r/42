/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 23:44:58 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/02 00:53:38 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/engine_utils.h"

t_queue	*create_queue(int size)
{
	t_queue	*res;

	res = malloc(sizeof(t_queue));
	if (!res)
		return (NULL);
	res->points = (t_point *)malloc(size * sizeof(t_point));
	if (!res->points)
	{
		free(res);
		return (NULL);
	}
	res->front = -1;
	res->rear = -1;
	res->size = size;
	return (res);
}

void	add_to_queue(t_queue *q, t_point pt)
{
	if ((q->rear + 1) % q->size == q->front)
		return ;
	if (q->front == -1)
	{
		q->front = 0;
		q->rear = 0;
	}
	else
		q->rear = (q->rear + 1) % q->size;
	q->points[q->rear] = pt;
}

t_point	remove_from_queue(t_queue *q)
{
	t_point	pt;

	pt = (t_point){-1, -1, 0, 0};
	if (q->front == -1)
		return (pt);
	pt = q->points[q->front];
	if (q->front == q->rear)
	{
		q->rear = -1;
		q->front = -1;
	}
	else
		q->front = (q->front + 1) % q->size;
	return (pt);
}

void	free_queue(t_queue *q)
{
	free(q->points);
	free(q);
}
