/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInDash1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:54 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/15 19:15:10 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In InDash
void	letter_when_in_dash(t_context *currState, t_states *mystates)
{
	printf("================= letter_when_in_dash ===========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_option_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("==================== letter_when_in_dash ========================\n");
}

void	other_when_in_dash(t_context *currState, t_states *mystates)
{
	letter_when_in_start(currState, mystates);
}

void	space_when_in_dash(t_context *currState, t_states *mystates)
{
	printf("=================== space_when_in_dash=========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("===================== space_when_in_dash =======================\n");
}
