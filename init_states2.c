/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_state2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:16 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:44:07 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_implement_handlers	*init_state_invalid(t_implement_handlers *mystates)
{
	mystates->in_invalid_state->handler_letter = &stay_in_invalid;
	return (mystates);
}

t_implement_handlers	*init_state_success(t_implement_handlers *mystates)
{
	mystates->in_success_state->handler_letter = &to_end_success;
	return (mystates);
}

t_implement_handlers	*init_states(void)
{
	t_implement_handlers	*mystates;

	mystates = malloc(sizeof(t_implement_handlers));
	if (!mystates)
		return (NULL);
	mystates = init_state_start(mystates);
	mystates = init_state_dash(mystates);
	mystates = init_state_option(mystates);
	mystates = init_state_space(mystates);
	mystates = init_state_invalid(mystates);
	mystates = init_state_number(mystates);
	mystates = init_state_success(mystates);
	return (mystates);
}

void	free_mystates(t_implement_handlers *mystates)
{
	if (mystates)
		free(mystates);
	mystates = NULL;
}
