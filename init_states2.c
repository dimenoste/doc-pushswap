/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_states2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:00:16 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:14:09 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_state_interface	*init_option_state(void)
{
	t_state_interface	*ptr_in_option_state;

	ptr_in_option_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_option_state)
		return (NULL);
	ptr_in_option_state->handler_letter = &letter_when_in_option;
	ptr_in_option_state->handler_space = &space_when_in_option;
	ptr_in_option_state->handler_digit = &digit_when_in_option;
	ptr_in_option_state->handler_dash = &dash_when_in_option;
	ptr_in_option_state->handler_other = &other_when_in_option;
	ptr_in_option_state->handler_end = &end_when_in_option;
	return (ptr_in_option_state);
}

t_state_interface	*init_invalid_state(void)
{
	t_state_interface	*ptr_in_invalid_state;

	ptr_in_invalid_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_invalid_state)
		return (NULL);
	ptr_in_invalid_state->handler_letter = &stay_in_invalid;
	return (ptr_in_invalid_state);
}

t_state_interface	*init_success_state(void)
{
	t_state_interface	*ptr_in_success_state;

	ptr_in_success_state = malloc(sizeof(t_state_interface));
	if (!ptr_in_success_state)
		return (NULL);
	ptr_in_success_state->handler_letter = &to_end_success;
	return (ptr_in_success_state);
}

void	free_mystates(t_states *mystates)
{
	if (!mystates)
	{
		return ;
	}
	if (mystates->ptr_in_dash_state)
		free(mystates->ptr_in_dash_state);
	if (mystates->ptr_in_invalid_state)
		free(mystates->ptr_in_invalid_state);
	if (mystates->ptr_in_number_state)
		free(mystates->ptr_in_number_state);
	if (mystates->ptr_in_option_state)
		free(mystates->ptr_in_option_state);
	if (mystates->ptr_in_space_state)
		free(mystates->ptr_in_space_state);
	if (mystates->ptr_in_start_state)
		free(mystates->ptr_in_start_state);
	if (mystates->ptr_in_success_state)
		free(mystates->ptr_in_success_state);
	free(mystates);
	mystates = NULL;
}
