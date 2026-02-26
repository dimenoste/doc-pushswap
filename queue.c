/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:49:39 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/21 19:59:50 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_node;

typedef struct queue
{
	t_node		*front;
	t_node		*rear;
}				t_queue;

t_node	*node_create(int data)
{
	t_node	*ptr_node;

	ptr_node = malloc(sizeof(t_node));
	if (!ptr_node)
		return (NULL);
	ptr_node->data = data;
	ptr_node->next = NULL;
	return (ptr_node);
}

t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue->front = NULL;
	queue->rear = NULL;
	return (queue);
}

void	free_queue(t_queue *queue)
{
	t_node	*ptr;
	t_node	*prev;

	if (!queue || !queue->front)
		return ;
	ptr = queue->front;
	while (ptr)
	{
		prev = ptr;
		ptr = ptr->next;
		free(prev);
	}
	free(queue);
	return ;
}

t_queue	*enqueue(t_queue *queue, int val)
{
	t_node	*ptr_node;

	ptr_node = node_create(val);
	if (!ptr_node)
		return (queue);
	if (!queue)
		queue = create_queue();
	if (queue->front == NULL)
	{
		queue->front = ptr_node;
		queue->rear = ptr_node;
	}
	else
	{
		if (!queue->rear)
			return (queue);
		ptr_node->next = NULL;
		queue->rear->next = ptr_node;
		queue->rear = ptr_node;
	}
	return (queue);
}

int	dequeue(t_queue *queue, void **data)
{
	if (!queue || !queue->front)
		return (0);
	*data = (void *)queue->front;
	queue->front = queue->front->next;
	return (1);
}

void	display_queue(t_queue *queue)
{
	t_node	*ptr;
	int		i;

	i = 0;
	if (!queue || !queue->front)
	{
		printf("queue is empty");
		return ;
	}
	ptr = queue->front;
	while (ptr != queue->rear->next)
	{
		printf("value of %ith node in queue is %d\n", i, ptr->data);
		i++;
		ptr = ptr->next;
	}
	return ;
}

void	*queue_peek(t_queue *queue)
{
	if (!queue)
		return (NULL);
	return (queue->front);
}

int	queue_size(t_queue *queue)
{
	int		i;
	t_node	*node;

	i = 0;
	if (!queue || !queue->front)
		return (i);
	node = queue->front;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}

int	main(void)
{
	t_queue *queue;
	void *elem_dequeued;

	int nber_dequeued = 0;

	queue = create_queue();
	queue = enqueue(queue, 12);
	queue = enqueue(queue, 2);
	queue = enqueue(queue, -15);
	queue = enqueue(queue, 6);

	display_queue(queue);

	dequeue(queue, &elem_dequeued);
	nber_dequeued = ((t_node *)elem_dequeued)->data;
	printf("len of queue %d\n", queue_size(queue));

	display_queue(queue);
	printf("numbered dequeue %d\n", nber_dequeued);
	printf("len of queue %d\n", queue_size(queue));
	free_queue(queue);
	free(elem_dequeued);

	return (0);
}