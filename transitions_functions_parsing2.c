/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions_functions_parsing2.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:31:11 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:43:41 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	toin_invalid_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InInvalid;
	currState->interface = mystates->ptr_in_invalid_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_number_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InNumber;
	currState->interface = mystates->ptr_in_number_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits += 1;
}

void	to_end_success(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InSuccess;
	currState->interface = mystates->ptr_in_success_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}
