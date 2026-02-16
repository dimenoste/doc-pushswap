/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reactions_WhenInStart1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberraho <mehdi.berraho@learner.42.tech    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 13:52:48 by mberraho          #+#    #+#             */
/*   Updated: 2026/02/15 19:15:10 by mberraho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// In Start
void	letter_when_in_start(t_context *currState, t_states *mystates)
{
	printf("=================== letter_when_in_start =========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_invalid_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("===================== letter_when_in_start =======================\n");
}

void	other_when_in_start(t_context *currState, t_states *mystates)
{
	letter_when_in_start(currState, mystates);
}

void	space_when_in_start(t_context *currState, t_states *mystates)
{
	printf("==================== space_when_in_start ========================\n");
	printf("current state is : %s\n", get_state_name(currState->name_state));
	toin_space_state(currState, mystates);
	printf("current state is : %s\n", get_state_name(currState->name_state));
	printf("====================== space_when_in_start ======================\n");
}
