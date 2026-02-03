/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:31:09 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/03 17:53:47 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*new_node(long value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = node;
	node->previous = node;
	return (node);
}

t_stack	*new_stack(t_stack_name name)
{
	t_stack	*stk;

	stk = malloc(sizeof(t_stack));
	if (!stk)
		return (NULL);
	stk->head = NULL;
	stk->tail = NULL;
	stk->length = 0;
	stk->name = name;
	return (stk);
}

void	clear_stack(t_stack **stk)
{
	t_node	*next;
	t_node	*current;

	if (!stk || !(*stk))
		return ;
	if ((*stk)->length == 0)
	{
		free(*stk);
		*stk = NULL;
		return ;
	}
	current = (*stk)->head;
	(*stk)->tail->next = NULL;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(*stk);
	*stk = NULL;
}
