/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:12:51 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/02/26 18:12:53 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_inversions_from(t_node *ref, size_t start, size_t len)
{
	t_node	*cur_j;
	size_t	j;
	size_t	inv;

	cur_j = ref->next;
	j = start + 1;
	inv = 0;
	while (j < len)
	{
		if (ref->value > cur_j->value)
			inv++;
		cur_j = cur_j->next;
		j++;
	}
	return (inv);
}

float	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;
	t_node	*cur_i;
	size_t	i;

	if (!a || a->length < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	cur_i = a->head;
	i = 0;
	while (i < a->length)
	{
		mistakes += count_inversions_from(cur_i, i, a->length);
		total_pairs += a->length - 1 - i;
		cur_i = cur_i->next;
		i++;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}
