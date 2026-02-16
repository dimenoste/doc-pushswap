/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:31:09 by yasmine.aic       #+#    #+#             */
/*   Updated: 2026/02/16 18:20:14 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_empty_stack(t_stack *stk)
{
	if (stk == NULL)
		return (TRUE);
	return (stk->head == NULL);
}

size_t	stack_length(t_stack *stk)
{
	if (is_empty_stack(stk))
		return (0);
	return (stk->length);
}

t_node	*stack_first(t_stack *stk)
{
	if (is_empty_stack(stk))
		return (NULL);
	return (stk->head);
}

long	stack_top_peek(t_stack *stk)
{
	if (is_empty_stack(stk))
		return (0);
	return (stk->head->value);
}

t_node	*stack_last(t_stack *stk)
{
	if (is_empty_stack(stk))
		return (NULL);
	return (stk->tail);
}
