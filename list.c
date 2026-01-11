/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:15:16 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/11 16:36:25 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*new_list(void)
{
	return (NULL);
}

t_bool	is_empty(t_list *lst)
{
	if (lst == NULL)
		return (TRUE);
	return (FALSE);
}

t_bool	is_empty_node(t_stack *stk)
{
	if (stk == NULL)
		return (TRUE);
	return (stk->head == NULL);
}

long	stack_length(t_stack *stk)
{
	if (is_empty_stack(stk))
		return (0);
	return (stk->length);
}

long	stack_first(t_stack *stk)
{
	if (is_empty_stack(stk))
		exit(1);
	return (stk->head->value);
}

long	stack_last(t_stack *stk)
{
	if (is_empty_stack(stk))
		exit(1);
	return (stk->tail->value);
}
