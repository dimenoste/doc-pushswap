/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_state2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:16 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 18:15:41 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_implement_handlers	*init_state_invalid(t_implement_handlers *mystates)
{
	mystates->InNumberState->handler_letter = &stayInInvalid;
	return (mystates);
}

t_implement_handlers	*init_state_success(t_implement_handlers *mystates)
{
	mystates->InNumberState->handler_letter = &toEndSuccess;
	return (mystates);
}

t_implement_handlers	*init_states(void)
{
	struct toto	*mystates;

	mystates = malloc(sizeof(t_implement_handlers));
	if (!mystates)
		return (NULL);
	mystates = init_state_start(mystates);
	mystates = init_state_dash(mystates);
	mystates = init_state_space(mystates);
	mystates = init_state_number(mystates);
	mystates = init_state_number(mystates);
	mystates = init_state_invalid(mystates);
	mystates = init_state_success(mystates);
	return (mystates);
}

void	free_mystates(t_implement_handlers *mystates)
{
	if (mystates)
		free(mystates);
	mystates = NULL;
}