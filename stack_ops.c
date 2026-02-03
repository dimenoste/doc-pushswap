/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:42:05 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/03 18:41:21 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_back(t_stack *stk, t_node *node)
{
	if (!stk || !node)
		return ;
	if (stk->length == 0)
	{
		stk->head = node;
		stk->tail = node;
	}
	else
	{
		node->next = stk->head;
		node->previous = stk->tail;
		stk->tail->next = node;
		stk->head->previous = node;
		stk->tail = node;
	}
	stk->length++;
}

/*
 * stack_add_front - Adds a node at the beginning of the stack
 */
void	stack_add_front(t_stack *stk, t_node *node)
{
	if (!stk || !node)
		return ;
	if (stk->length == 0)
	{
		stk->head = node;
		stk->tail = node;
	}
	else
	{
		node->next = stk->head;
		node->previous = stk->tail;
		stk->tail->next = node;
		stk->head->previous = node;
		stk->head = node;
	}
	stk->length++;
}

/*
 * stack_pop_front - Removes and returns the first node
 *
 * Return: The removed node (detached, with NULL pointers) or NULL if empty
 *
 * IMPORTANT: The returned node has next/previous set to NULL.
 * It must be re-integrated into a stack using stack_add_back/front.
 */
t_node	*stack_pop_front(t_stack *from)
{
	t_node	*elem;

	if (!from || from->length == 0)
		return (NULL);
	elem = from->head;
	if (from->length == 1)
	{
		from->head = NULL;
		from->tail = NULL;
	}
	else
	{
		from->head = elem->next;
		from->head->previous = from->tail;
		from->tail->next = from->head;
	}
	elem->next = NULL;
	elem->previous = NULL;
	from->length--;
	return (elem);
}
