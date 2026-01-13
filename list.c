/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:15:16 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/13 18:50:21 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
#include <stdlib.h>

t_list	*new_list(void)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (!root)
		exit(1);
	else
	{
		root->previous = root;
		root->next = root;
	}
	return (root);
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
	if (is_empty_node(stk))
		exit(1);
	return (stk->length);
}

t_list	*stack_first(t_stack *stk)
{
	if (is_empty_node(stk))
		exit(1);
	return (stk->head);
}

t_list	*stack_last(t_stack *stk)
{
	if (is_empty_node(stk))
		exit(1);
	return (stk->tail);
}

/*
	* void	lst_add_front(t_stack *stack, long value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->value = value;
		// Si stack vide
		if (stack->head == NULL)
	{
		// ??? comment connecter new_node à lui-même (circulaire) ???
		// ??? mettre à jour stack->head et stack->tail ???
	}
	else
	{
		// ??? connecter new_node entre tail et head ???
		// ??? mettre à jour stack->head ???
	}
	stack->length++;
}
*/
