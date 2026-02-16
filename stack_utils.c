/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:39:32 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/15 19:37:36 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node	*current;
	size_t	i;

	if (is_empty_stack(stack))
	{
		printf("empty stack\n");
		return ;
	}
	printf("[Stack %s, length=%zu]: ", name, stack->length);
	current = stack->head;
	i = 0;
	while (i < stack->length)
	{
		printf("%ld", current->value);
		if (i < stack->length - 1)
			printf(" → ");
		current = current->next;
		i++;
	}
	printf("\n");
}
// add node to stack and return 1 or 0 if value in node is unique or not respectively
int	is_node_unique(t_stack *stk, t_node *node)
{
	t_node *orig_head;
	stack_add_back(stk, node);

	if (!stk || !node)
		return (0);
	orig_head = stk->head;
	while (stk->head != stk->tail)
	{
		if (stk->head->value == node->value)
		{
			printf("Error A GARDER EN Error a changer avec write sortie 2\n");
			//
			stk->head = orig_head;
			return (0);
		}
		stk->head = stk->head->next;
	}
	stk->head = orig_head;
	return (1);
}