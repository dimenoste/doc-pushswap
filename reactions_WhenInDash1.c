/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInDash1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 22:56:56 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In InDash
void	letter_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_option_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	other_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	letter_when_in_start(currState, mystates);
}

void	space_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	digit_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash == 1)
	{
		currState->start_number = currState->addr_first_dash;
		toin_number_state(currState, mystates);
		currState->nber_dash = 0;
	}
	else if (currState->nber_dash == 0)
	{
		currState->start_number = currState->addr_first_dash; // pas sur de ca
		toin_number_state(currState, mystates);
		currState->nber_dash = 0;
	}
	else
		toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	// reset dash counter to 0
	printf("============================================\n");
}

void	dash_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	if (currState->nber_dash < 2)
	{
		toin_dash_state(currState, mystates);
	}
	else
		toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	end_when_in_dash(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("============================================\n");
}
