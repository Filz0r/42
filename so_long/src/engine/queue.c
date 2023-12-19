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

/**
 * @brief Creates a pointer to a t_queue based on the given size
 * @param size the number of elements we want our queue to have at max
 * @return either returns NULL if malloc fails, or an valid pointer to a
 * t_queue structure.
 */
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

/**
 * @brief Adds the given t_point struct to our queue, note that this queue
 * system works in a circular manner, this means that if our queue is full
 * this function does not add anything to the queue.
 * @param queue a pointer to a valid t_queue structure
 * @param pt a t_point we want to add to our queue.
 */
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

/**
 * @brief removes a t_point structure from the given queue pointer
 * @param queue a t_queue pointer that contains a queue we want to remove
 * elements from
 * @return if the queue is empty this will return a t_point with -1 inside
 * that needs to be used for error handling, otherwise it will return the value
 * in the front of our queue (this means that the queue system works with a
 * first in first out logic)
 */
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

/**
 * @brief frees the memory of the given t_queue pointer
 * @param queue a pointer to an valid t_queue structure
 */
void	free_queue(t_queue *q)
{
	if (!q)
		return ;
	free(q->points);
	free(q);
}
