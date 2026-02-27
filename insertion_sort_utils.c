/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:09:09 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/27 17:38:49 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_max_pos(t_stack *stk)
{
	t_node	*current;
	long	max_val;
	size_t	max_pos;
	size_t	i;

	current = stk->head;
	max_val = current->value;
	max_pos = 0;
	i = 1;
	while (i < stk->length)
	{
		current = current->next;
		if (current->value > max_val)
		{
			max_val = current->value;
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}

t_node	*get_node_at(t_stack *stk, size_t pos)
{
	t_node	*current;
	size_t	i;

	current = stk->head;
	i = 0;
	while (i < pos)
	{
		current = current->next;
		i++;
	}
	return (current);
}

void	rotate_to_top(t_stack *stk, size_t pos, t_op_list *ops)
{
	size_t	i;

	if (pos == 0)
		return ;
	i = 0;
	if (pos <= stk->length / 2)
	{
		while (i < pos)
		{
			rotate(stk, ops);
			i++;
		}
	}
	else
	{
		while (i < stk->length - pos)
		{
			reverse_rotate(stk, ops);
			i++;
		}
	}
}

void	push_all_to_a(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	max_pos;

	if (b->length == 0)
		return ;
	max_pos = find_max_pos(b);
	rotate_to_top(b, max_pos, ops);
	while (b->length > 0)
		push(b, a, ops);
}
