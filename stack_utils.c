/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 18:39:32 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/14 18:48:41 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack, const char *name)
{
	t_node *current;
	size_t i;

	printf("[Stack %s, length=%zu]: ", name, stack->length);
	if (is_empty_stack(stack))
	{
		printf("empty stack\n");
		return ;
	}
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