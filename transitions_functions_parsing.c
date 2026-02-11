/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions_functions_parsing.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:30:29 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:44:07 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// transitions
void	toin_start_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InStart;
	currState->interface = mystates->in_start_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_dash_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InDash;
	currState->interface = mystates->in_dash_state;
	currState->name_state = enum_name;
	currState->nber_dash += 1;
	currState->nber_digits = 0;
}

void	toin_option_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InOption;
	currState->interface = mystates->in_option_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_space_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InSpace;
	currState->interface = mystates->in_space_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_invalid_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InInvalid;
	currState->interface = mystates->in_invalid_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_number_state(t_context_state *currState,
		t_implement_handlers *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InNumber;
	currState->interface = mystates->in_number_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits += 1;
}

void	to_end_success(t_context_state *currState, t_implement_handlers *mystates)
{
	t_enum_state_name enum_name;

	enum_name = InSuccess;
	currState->interface = mystates->in_success_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}