/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions_functions_parsing.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:30:29 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/16 18:53:19 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	toin_start_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InStart;
	currState->interface = mystates->ptr_in_start_state;
	currState->name_state = enum_name;
	currState->mystring = NULL;
	currState->addr_first_dash = NULL;
	currState->bench_found = NULL;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
	currState->start_number = NULL;
	currState->option_found = NULL;
}

void	toin_dash_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InDash;
	currState->interface = mystates->ptr_in_dash_state;
	currState->name_state = enum_name;
	currState->nber_dash += 1;
	currState->nber_digits = 0;
}

void	toin_option_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InOption;
	currState->interface = mystates->ptr_in_option_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toin_space_state(t_context *currState, t_states *mystates)
{
	t_enum_state_name	enum_name;

	enum_name = InSpace;
	currState->interface = mystates->ptr_in_space_state;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}
