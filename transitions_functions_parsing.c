/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transitions_functions_parsing.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:30:29 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/09 13:38:48 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// transitions
void	toStartState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InStart;
	currState->interface = &InStartState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInDashState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InDash;
	currState->interface = &InDashState;
	currState->name_state = enum_name;
	currState->nber_dash += 1;
	currState->nber_digits = 0;
}

void	toInOptionState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InOption;
	currState->interface = &InOptionState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInSpaceState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InSpace;
	currState->interface = &InSpaceState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInInvalidState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InInvalid;
	currState->interface = &InInvalidState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}

void	toInNumberState(contextState *currState)
{
	e_state_name	enum_name;

	enum_name = InNumber;
	currState->interface = &InNumberState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits += 1;
}

void	toEndSuccess(contextState *currState)
{
	e_state_name enum_name;

	enum_name = InSuccess;
	currState->interface = &InSuccessState;
	currState->name_state = enum_name;
	currState->nber_dash = 0;
	currState->nber_digits = 0;
}