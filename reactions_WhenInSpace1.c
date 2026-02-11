/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInSpace1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:28:08 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/11 16:44:48 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In SpaceState
void	letter_when_in_space(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	other_when_in_space(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}

void	space_when_in_space(t_context_state *currState,
		t_implement_handlers *mystates)
{
	printf("============================================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_space_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("============================================\n");
}
