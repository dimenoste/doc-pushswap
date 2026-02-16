/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 17:38:44 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/16 18:15:10 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, t_op_list *ops)
{
	if (!stack || stack->length < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->head->previous;
	if (stack->name == A)
		add_operation(ops, OP_RA);
	else
		add_operation(ops, OP_RB);
}

void	rotate_both(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a && a->length >= 2)
	{
		a->head = a->head->next;
		a->tail = a->head->previous;
	}
	if (b && b->length >= 2)
	{
		b->head = b->head->next;
		b->tail = b->head->previous;
	}
	add_operation(ops, OP_RR);
}

void	reverse_rotate(t_stack *stack, t_op_list *ops)
{
	if (!stack || stack->length < 2)
		return ;
	stack->tail = stack->tail->previous;
	stack->head = stack->tail->next;
	if (stack->name == A)
		add_operation(ops, OP_RRA);
	else
		add_operation(ops, OP_RRB);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_op_list *ops)
{
	if (a && a->length >= 2)
	{
		a->tail = a->tail->previous;
		a->head = a->tail->next;
	}
	if (b && b->length >= 2)
	{
		b->tail = b->tail->previous;
		b->head = b->tail->next;
	}
	add_operation(ops, OP_RRR);
}
