/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 23:08:07 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/27 17:40:19 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *a, t_op_list *ops)
{
	if (a->head->value > a->head->next->value)
		swap(a, ops);
}

void	sort_three(t_stack *a, t_op_list *ops)
{
	long	first;
	long	second;
	long	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first > second && second < third && first < third)
		swap(a, ops);
	else if (first > second && second > third)
	{
		swap(a, ops);
		reverse_rotate(a, ops);
	}
	else if (first > second && first > third)
		rotate(a, ops);
	else if (first < second && second > third && first < third)
	{
		swap(a, ops);
		rotate(a, ops);
	}
	else if (first < second && second > third)
		reverse_rotate(a, ops);
}

size_t	find_insert_pos_b(t_stack *b, long value)
{
	t_node	*cur;
	size_t	pos;
	size_t	max_pos;

	if (b->length == 0)
		return (0);
	max_pos = find_max_pos(b);
	if (value > get_node_at(b, max_pos)->value)
		return (max_pos);
	pos = (max_pos + b->length - 1) % b->length;
	if (value < get_node_at(b, pos)->value)
		return (max_pos);
	cur = b->head;
	pos = 0;
	while (pos < b->length)
	{
		if (cur->value > value && cur->next->value < value)
			return ((pos + 1) % b->length);
		cur = cur->next;
		pos++;
	}
	return (max_pos);
}

static void	insert_to_b(t_stack *a, t_stack *b, t_op_list *ops)
{
	size_t	pos;

	pos = find_insert_pos_b(b, a->head->value);
	rotate_to_top(b, pos, ops);
	push(a, b, ops);
}

void	insertion_sort(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a->length <= 1)
		return ;
	if (a->length == 2)
	{
		sort_two(a, ops);
		return ;
	}
	if (a->length == 3)
	{
		sort_three(a, ops);
		return ;
	}
	while (a->length > 0)
		insert_to_b(a, b, ops);
	push_all_to_a(a, b, ops);
}
