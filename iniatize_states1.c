/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iniatize_states1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:52:03 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 15:20:04 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_implement_handlers	*init_state_start(t_implement_handlers *mystates)
{
	mystates->in_start_state->handler_letter = &letter_when_in_start;
	mystates->in_start_state->handler_space = &space_when_in_start;
	mystates->in_start_state->handler_digit = &digit_when_in_start;
	mystates->in_start_state->handler_dash = &dash_when_in_start;
	mystates->in_start_state->handler_other = &other_when_in_start;
	mystates->in_start_state->handler_end = &end_when_in_start;
	return (mystates);
}

t_implement_handlers	*init_state_dash(t_implement_handlers *mystates)
{
	mystates->in_dash_state->handler_letter = &letter_when_in_dash;
	mystates->in_dash_state->handler_space = &space_when_in_dash;
	mystates->in_dash_state->handler_digit = &digit_when_in_dash;
	mystates->in_dash_state->handler_dash = &dash_when_in_dash;
	mystates->in_dash_state->handler_other = &other_when_in_dash;
	mystates->in_dash_state->handler_end = &end_when_in_dash;
	return (mystates);
}

t_implement_handlers	*init_state_space(t_implement_handlers *mystates)
{
	mystates->in_space_state->handler_letter = &letter_when_in_space;
	mystates->in_space_state->handler_space = &space_when_in_space;
	mystates->in_space_state->handler_digit = &digit_when_in_space;
	mystates->in_space_state->handler_dash = &dash_when_in_space;
	mystates->in_space_state->handler_other = &other_when_in_space;
	mystates->in_space_state->handler_end = &end_when_in_space;
	return (mystates);
}
t_implement_handlers	*init_state_option(t_implement_handlers *mystates)
{
	mystates->in_option_state->handler_letter = &letter_when_in_option;
	mystates->in_option_state->handler_space = &space_when_in_option;
	mystates->in_option_state->handler_digit = &digit_when_in_option;
	mystates->in_option_state->handler_dash = &dash_when_in_option;
	mystates->in_option_state->handler_other = &other_when_in_option;
	mystates->in_option_state->handler_end = &end_when_in_option;
	return (mystates);
}

t_implement_handlers	*init_state_number(t_implement_handlers *mystates)
{
	mystates->in_number_state->handler_letter = &letter_when_in_number;
	mystates->in_number_state->handler_space = &space_when_in_number;
	mystates->in_number_state->handler_digit = &digit_when_in_number;
	mystates->in_number_state->handler_dash = &dash_when_in_number;
	mystates->in_number_state->handler_other = &other_when_in_number;
	mystates->in_number_state->handler_end = &end_when_in_number;
	return (mystates);
}
