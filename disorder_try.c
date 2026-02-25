/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_try.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:22:41 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/25 21:45:31 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yasmine.aichi <yasmine.aichi@learner.42.t  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:46:50 by yasmine.aichi     #+#    #+#             */
/*   Updated: 2026/01/27 23:46:58 by yasmine.aichi    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_mistakes_and_pairs(t_stack *a, size_t *mistakes,
		size_t *total_pairs)
{
	t_node	*current_i;
	t_node	*current_j;
	size_t	i;
	size_t	j;

	current_i = a->head;
	i = 0;
	while (i < a->length)
	{
		current_j = current_i->next;
		j = i + 1;
		while (j < a->length)
		{
			(*total_pairs)++;
			if (current_i->value > current_j->value)
				(*mistakes)++;
			current_j = current_j->next;
			j++;
		}
		current_i = current_i->next;
		i++;
	}
}
float	compute_disorder(t_stack *a)
{
	size_t	mistakes;
	size_t	total_pairs;

	if (!a || a->length < 2)
		return (0.0f);
	mistakes = 0;
	total_pairs = 0;
	get_mistakes_and_pairs(a, &mistakes, &total_pairs);
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}
